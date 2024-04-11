#include <iostream>
#include <algorithm>
using namespace std;

int nxt[3000000][2];
int sz[3000000];
int C;

void add(int v,int dif)
{
	int i = 1;
	for(int j=27;j>=0;j--)
	{
		if(nxt[i][(v&(1<<j))>0]==0)
			nxt[i][(v&(1<<j))>0] = C++;
		i = nxt[i][(v&(1<<j))>0];
		sz[i] += dif;
	}
}

int getCount(int p,int l)
{
	int i = 1;
	int ans = 0;
	for(int j=27;j>=0;j--)
	{
		int bReq = ((p^l)&(1<<j))>0;
		if(l&(1<<j)) ans += sz[nxt[i][bReq^1]];
		i = nxt[i][bReq];
	}
	return ans;
}

int main()
{
	int Q;
	cin >> Q;
	int tp,p,l;
	C = 2;
	for(int i=0;i<Q;i++)
	{
		cin >> tp >> p;
		if(tp==1) add(p,1);
		else if(tp==2) add(p,-1);
		else
		{
			cin >> l;
			cout << getCount(p,l) << '\n';
		}
	}
}