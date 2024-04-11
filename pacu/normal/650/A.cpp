#include <iostream>
#include <algorithm>
using namespace std;

int x[200000],y[200000],cid[200000];
int N;

bool cmpx(int a,int b)
{
	if(x[a]==x[b]) return y[a]<y[b];
	return x[a]<x[b];
}
bool cmpy(int a,int b)
{
	if(y[a]==y[b]) return x[a]<x[b];
	return y[a]<y[b];
}

int main()
{
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> x[i] >> y[i];
		cid[i] = i;
	}
	sort(cid,cid+N,cmpx);
	int j = 0;
	long long ans = 0;
	for(int i=0;i<N;i++)
	{
		while(x[cid[j]] < x[cid[i]]) j++;
		ans += i-j;
	}
	sort(cid,cid+N,cmpy);
	j = 0;
	for(int i=0;i<N;i++)
	{
		while(y[cid[j]] < y[cid[i]]) j++;
		ans += i-j;
	}
	j = 0;
	for(int i=0;i<N;i++)
	{
		while(y[cid[j]] < y[cid[i]] || x[cid[j]]<x[cid[i]]) j++;
		ans -= i-j;
	}
	cout << ans << '\n';
}