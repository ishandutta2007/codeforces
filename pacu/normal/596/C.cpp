#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int x[100000],y[100000],num[100000];
int w[100000];
int cid[100000];

vector<int> diag[200001];
int pos[200001];

bool cmp(int a,int b)
{
	if(x[a]==x[b]) return y[a]<y[b];
	return x[a]<x[b];
}

bool cmp2(int a,int b)
{
	if(y[a]==y[b]) return x[a]<x[b];
	return y[a]<y[b];
}

bool cmp3(int a,int b)
{
	return num[a]<num[b];
}

int main()
{
	int N;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> x[i] >> y[i];
		cid[i] = i;
	}
	sort(cid,cid+N,cmp);
	for(int i=0;i<N;i++)
	{
		cin >> w[i];
		diag[w[i]+100000].push_back(i);
	}
	for(int i=0;i<N;i++)
	{
		int c = y[cid[i]]-x[cid[i]]+100000;
		if(pos[c]==diag[c].size())
		{
			cout << "NO\n";
			return 0;
		}
		num[cid[i]] = diag[c][pos[c]++];
	}
	for(int i=1;i<N;i++)
		if(x[cid[i-1]]==x[cid[i]] && num[cid[i-1]] > num[cid[i]])
		{
			cout << "NO\n";
			return 0;
		}
	sort(cid,cid+N,cmp2);
	for(int i=1;i<N;i++)
		if(y[cid[i-1]]==y[cid[i]] && num[cid[i-1]] > num[cid[i]])
		{
			cout << "NO\n";
			return 0;
		}
	cout << "YES\n";
	sort(cid,cid+N,cmp3);
	for(int i=0;i<N;i++)
		cout << x[cid[i]] << ' ' << y[cid[i]] << '\n';
}