#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
int r[100000];
int a[100000],b[100000];

int fid[200000];

int find(int i)
{
	if(fid[i]==i) return i;
	return fid[i] = find(fid[i]);
}

void join(int i,int j)
{
	i = find(i), j = find(j);
	fid[i] = j;
}

int main()
{
	cin >> N >> M;
	for(int i=0;i<N;i++)
	{
		cin >> r[i];
		a[i] = -1;
	}
	int num,v;
	for(int i=0;i<2*M;i++)
		fid[i] = i;
	for(int i=0;i<M;i++)
	{
		cin >> num;
		for(int j=0;j<num;j++)
		{
			cin >> v;
			v--;
			if(a[v]==-1) a[v] = i;
			else
			{
				b[v] = i;
				if(r[v]==0) join(2*a[v],2*b[v]+1), join(2*b[v],2*a[v]+1);
				else join(2*a[v],2*b[v]), join(2*a[v]+1,2*b[v]+1);
			}
		}
	}
	for(int i=0;i<M;i++)
	{
		if(find(2*i) == find(2*i+1))
		{
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}