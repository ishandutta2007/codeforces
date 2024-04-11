#include <bits/stdc++.h>
#define MAXN 300007
using namespace std;
int seg[8*MAXN],bag[8*MAXN],p[MAXN],q[MAXN],pi[MAXN];
void lazy(int ind)
{
	seg[ind]+=bag[ind];
	bag[2*ind]+=bag[ind];
	bag[2*ind+1]+=bag[ind];
	bag[ind]=0;
}
void upd(int l,int r,int lt,int rt,int v,int ind)
{
	if(l>rt || r<lt) return;
	if(l>=lt && r<=rt) {bag[ind]+=v; return;}
	int s=(l+r)/2;
	lazy(ind);
	upd(l,s,lt,rt,v,2*ind);
	upd(s+1,r,lt,rt,v,2*ind+1);
	seg[ind]=min(seg[2*ind]+bag[2*ind],seg[2*ind+1]+bag[2*ind+1]);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&p[i]);
	for(int i=1;i<=n;i++) scanf("%d",&q[i]);
	for(int i=1;i<=n;i++) pi[p[i]]=i;
	int t=n,cml=1;
	upd(0,2*n,2*pi[t]-1,2*n,1,1);
	for(int i=1;i<=n;i++)
	{
		while(cml==seg[1]+bag[1])
		{
			t--;
			upd(0,2*n,2*pi[t]-1,2*n,1,1);
			cml++;
		}
		printf("%d ",t);
		upd(0,2*n,2*q[i],2*n,-1,1);
		cml--;
	}
}