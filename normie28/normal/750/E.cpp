#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll star[200001];
struct seg
{
	int val[800001][5][5];
	void reset(ll l, ll r, ll cur)
	{
		if (l==r)
		{
			for (ll i=0;i<5;i++) for (ll j=0;j<5;j++)
			{
				val[cur][i][j]=-1e9;
			}
			for (ll i=0;i<5;i++) val[cur][i][i]=0;
			if (star[l]==2) {
			val[cur][0][1]=1; val[cur][1][1]=1; val[cur][2][2]=1; val[cur][3][3]=1; val[cur][4][4]=1;}
			else
			if (star[l]==0) {
			val[cur][0][0]=1; val[cur][1][2]=1; val[cur][2][2]=1; val[cur][3][3]=1; val[cur][4][4]=1;}
			else
			if (star[l]==1) {
			val[cur][0][0]=1; val[cur][1][1]=1; val[cur][2][3]=1; val[cur][3][3]=1; val[cur][4][4]=1;}
			else
			if (star[l]==7) {
			val[cur][0][0]=1; val[cur][1][1]=1; val[cur][2][2]=1; val[cur][3][4]=1; val[cur][4][4]=1;}
			else
			if (star[l]==6) for (ll i=0;i<3;i++) val[cur][i][i]=1;
			else
			if (star[l]!=6) for (ll i=0;i<5;i++) val[cur][i][i]=1;
		}
		else
		{
			ll mid=(l+r)/2;
			reset(l,mid,(cur<<1));
			reset(mid+1,r,(cur<<1)+1);
			for (ll i=0;i<5;i++) for (ll j=0;j<5;j++) val[cur][i][j]=-1e9;
			for (ll i=0;i<5;i++) for (ll j=i;j<5;j++) for (ll k=j;k<5;k++)
			val[cur][i][k]=max(val[cur][i][k],val[(cur<<1)][i][j]+val[(cur<<1)+1][j][k]);
		}
	//		cout<<l<<' '<<r<<' '<<cur<<" transitions:\n";
	//		for (ll i=0;i<5;i++) for (ll j=0;j<5;j++)
	//		{
	//			cout<<val[cur][i][j]<<' ';
	//			if (j==4) cout<<endl;
	//		}
	}
	void proc(ll l, ll r, ll cur, ll tl, ll tr, vector<ll> &v)
	{
		if ((tl>r)or(tr<l)) return;
		if ((tl<=l)and(tr>=r))
		{
	//	cout<<"proc "<<l<<' '<<r<<' '<<cur<<' '<<tl<<' '<<tr<<endl;
			vector<ll> vv(5,-1e9);
			for (ll i=0;i<5;i++) for (ll j=i;j<5;j++) vv[j]=max(vv[j],v[i]+val[cur][i][j]);
			v=vv;
	//		for (ll i=0;i<5;i++) cout<<v[i]<<' '; cout<<endl;
		}
		else
		{
			ll mid=(l+r)/2;
			proc(l,mid,(cur<<1),tl,tr,v);
			proc(mid+1,r,(cur<<1)+1,tl,tr,v);
		}
	}
};
seg st;
ll n,m,i,j,k,t,t1,u,v,a,b;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		char c;
		cin>>c;
		star[i]=c-48;
	}
	st.reset(1,n,1);
	for (i=1;i<=m;i++)
	{
		cin>>a>>b;
		vector<ll> c(5,-1e9);
		c[0]=0;
		st.proc(1,n,1,a,b,c);
	//	cout<<c[0]<<' '<<c[1]<<' '<<c[2]<<' '<<c[3]<<' '<<c[4]<<endl;
		if (c[4]<0) cout<<-1; else cout<<b-a+1-c[4];
		cout<<endl;
	}
}