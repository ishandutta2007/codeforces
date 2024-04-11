#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 10;
int t,n,m,a[N],A,s[N*3],v[N*3],L,R,y,z,b[N],x;
pair<int,int>p[N];
struct bit{
	int a[N];
	void Mdf(int x){for(;x<=n;x+=x&(-x))a[x]++;}
	int Qry(int x){int r=0;for(;x;x-=x&(-x))r+=a[x];return r;}
}	st;
void C(int k,int l,int r)
{
	if(L<=l&&r<=R)
	{
		v[k]+=y,s[k]+=y;
		return;
	}
	v[2*k]+=v[k],s[2*k]+=v[k],v[2*k+1]+=v[k],s[2*k+1]+=v[k],v[k]=0;
	int d=(l+r)/2;
	if(L<=d)
		C(2*k,l,d);
	if(R>d)
		C(2*k+1,d+1,r);
	s[k]=min(s[2*k],s[2*k+1]);
}
int F[N], cnt;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>t;
	while(t--&&cin>>n>>m)
	{
		A=0;
		for(int i=1;i<=n;i++)
			cin>>a[i],p[i]=make_pair(a[i],i);
		cnt=0;
		for(int i=1;i<=n;i++)
			F[++cnt]=a[i];
		sort(F+1,F+cnt+1);
		cnt=unique(F+1,F+cnt+1)-F-1;
		for (int i=1;i<=n;i++)
			st.a[i]=0;
		for (int i=1;i<=n;i++)
		{
			int t=lower_bound(F+1,F+cnt+1,a[i])-F;
			A+=(i-1)-st.Qry(t);
			st.Mdf(t);
		}
		for(int i=1;i<=m;i++)
			cin>>b[i];
		sort(b+1,b+m+1),sort(p+1,p+n+1);
		for(int i=1;i<=(n+1)*5;i++)
			v[i]=s[i]=0;
		for(int i=1;i<=n;i++) {
			L=p[i].second+1,R=n+1,y=1,C(1,1,n+1);
		}
		x=1;
		for(int i=1;i<=m;i++)
		{
			while(p[x].first<b[i]&&x<=n) {
				L=p[x].second+1,R=n+1,y=-1,C(1,1,n+1);
				L=1,R=p[x].second,y=1,C(1,1,n+1),x++;
			}
			if(b[i]>b[i-1])
				while(p[x].first==b[i]&&x<=n) {
					L=p[x].second+1,R=n+1,y=-1,C(1,1,n+1),x++;
				}
			A+=s[1];
			if(i<m&&b[i]<b[i+1])
			{
				z=x,x--;
				while(p[x].first==b[i])
					L=1,R=p[x].second,y=1,C(1,1,n+1),x--;
				x=z;
			}
		}
		cout<<A<<endl;
	}
	return 0;
}