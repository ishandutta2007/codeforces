//This solution is based on the solution of tmt514.
//I promise that I did not copy it right away.
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define F first
#define S second
#define ll long long
#define N 200010
#define MN 1000010
#define M 450
using namespace std;
ll n,t,val[N],ans[N],fn,tms[MN];
struct q{
	int l,r,id;
	bool operator<(const q &p) const{
		return make_pair(l,r)<make_pair(p.l,p.r);
	}
};
vector<q> dq[M];
void add(ll x)
{
	fn+=(tms[x]*2+1)*x;
	tms[x]++;
	return;
}
void sub(ll x)
{
	fn-=(tms[x]*2-1)*x;
	tms[x]--;
	return;
}
int main(){
	ll i,j,x,y,z,sq;
	scanf("%I64d %I64d",&n,&t);
	sq=sqrt(n);
	for(i=0;i<n;i++)
	{
		scanf("%I64d",&val[i]);
	}
	for(i=0;i<t;i++)
	{
		q p;
		scanf("%I64d %I64d",&p.l,&p.r);
		p.l--;
		p.r--;
		z=p.r/sq;
		p.id=i;
		dq[z].push_back(p);
	}
	memset(tms,0,sizeof(tms));
	x=0;
	y=-1;
	fn=0;
	for(i=0;i*sq<=n;i++)
	{
		sort(dq[i].begin(),dq[i].end());
		for(j=0;j<dq[i].size();j++)
		{
			q &p=dq[i][j];
			while(y<p.r)
			{
				add(val[++y]);
			}
			while(y>p.r)
			{
				sub(val[y--]);
			}
			while(x<p.l)
			{
				sub(val[x++]);
			}
			while(x>p.l)
			{
				add(val[--x]);
			}
			ans[p.id]=fn;
		}
	}
	for(i=0;i<t;i++)
	{
		printf("%I64d\n",ans[i]);
	}
	return 0;
}