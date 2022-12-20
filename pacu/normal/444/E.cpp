#include <iostream>
#include <algorithm>
using namespace std;

int N;
int x[3000];
int a[3000],b[3000],l[3000],cid[3000];
bool cmp(int i,int j)
{
	return l[i]<l[j];
}
int fid[3000],sz[3000];
long long xsz[3000];
int imx;

void init()
{
	for(int i=0;i<N;i++)
		fid[i] = i, sz[i] = 1, xsz[i] = x[i];
}
int find(int i)
{
	if(fid[i]==i) return i;
	fid[i] = find(fid[i]);
	return fid[i];
}
void join(int i,int j)
{
	i = find(i), j = find(j);
	if(sz[i]<=sz[j])
	{
		fid[i] = j;
		sz[j] += sz[i];
		xsz[j] += xsz[i];
		if(sz[j] > sz[imx]) imx = j;
	}
	else
	{
		fid[j] = i;
		sz[i] += sz[j];
		xsz[i] += xsz[j];
		if(sz[i] > sz[imx]) imx = i;
	}
}

int main()
{
	cin >> N;
	for(int i=0;i<N-1;i++)
	{
		cin >> a[i] >> b[i] >> l[i];
		a[i]--,b[i]--;
		cid[i] = i;
	}
	long long tot = 0;
	for(int i=0;i<N;i++)
	{
		cin >> x[i];
		tot += x[i];
	}
	sort(cid,cid+N-1,cmp);
	init();
	for(int i=0;i<N-1;i++)
	{
		join(a[cid[i]],b[cid[i]]);
		if(sz[imx]+xsz[imx] > tot)
		{
			cout << l[cid[i]] << '\n';
			return 0;
		}
	}
	cout << 0 << '\n';
}