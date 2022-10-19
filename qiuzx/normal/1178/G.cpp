//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 200010
#define B 450
using namespace std;
ll n,q,a[N],b[N],suma[N],sumb[N],vala[N],valb[N],addsq[N],din[N],dout[N],par[N],seq[N],cnt=-1;
struct CVH{
	ll dx[B+20],dy[B+20],tot,beg,ed,q[B+20],curx;
	void init()
	{
		tot=beg=ed=0;
		curx=0;
		return;
	}
	void ins(ll x,ll y)
	{
		ll id=tot++;
		dx[id]=x;
		dy[id]=y;
		while(ed-beg>=2)
		{
			if((__int128)(dy[q[ed-1]]-dy[q[ed-2]])*(__int128)(x-dx[q[ed-1]])>(__int128)(y-dy[q[ed-1]])*(__int128)(dx[q[ed-1]]-dx[q[ed-2]]))
			{
				break;
			}
			--ed;
		}
		q[ed++]=id;
		return;
	}
	void upd(ll v)
	{
		curx+=v;
		while(beg+1<ed)
		{
			if((__int128)(dy[q[beg+1]]-dy[q[beg]])<(__int128)curx*(__int128)(dx[q[beg+1]]-dx[q[beg]]))
			{
				break;
			}
			++beg;
		}
		return;
	}
	ll qry(ll v)
	{
		return -curx*dx[q[beg]]+dy[q[beg]];
	}
}sq0[N/B+10];
struct CVH2{
	ll dx[B+20],dy[B+20],tot,beg,ed,q[B+20],curx;
	void init()
	{
		tot=beg=ed=0;
		curx=0;
		return;
	}
	void ins(ll x,ll y)
	{
		ll id=tot++;
		dx[id]=x;
		dy[id]=y;
		while(ed-beg>=2)
		{
			if((__int128)(dy[q[ed-1]]-dy[q[ed-2]])*(__int128)(x-dx[q[ed-1]])<(__int128)(y-dy[q[ed-1]])*(__int128)(dx[q[ed-1]]-dx[q[ed-2]]))
			{
				break;
			}
			--ed;
		}
		q[ed++]=id;
		return;
	}
	void upd(ll v)
	{
		curx+=v;
		while(beg+1<ed)
		{
			if((__int128)(dy[q[ed-1]]-dy[q[ed-2]])<(__int128)curx*(__int128)(dx[q[ed-1]]-dx[q[ed-2]]))
			{
				break;
			}
			--ed;
		}
		return;
	}
	ll qry(ll v)
	{
		return -curx*dx[q[ed-1]]+dy[q[ed-1]];
	}
}sq1[N/B+10];
vector<ll> vt[N];
bool cmp(ll x,ll y){return (x/B==y/B)?(valb[x]<valb[y]):(x/B<y/B);}
void dfs(ll x)
{
	din[x]=++cnt;
	suma[x]+=a[x];
	sumb[x]+=b[x];
	ll i;
	for(i=0;i<vt[x].size();i++)
	{
		suma[vt[x][i]]=suma[x];
		sumb[vt[x][i]]=sumb[x];
		dfs(vt[x][i]);
	}
	dout[x]=cnt;
	return;
}
void rebuild(ll l,ll r)
{
	ll id=l/B,i;
	sq0[id].init();
	sq1[id].init();
	for(i=l;i<=r;i++)
	{
		assert(i==l||valb[seq[i]]>=valb[seq[i-1]]);
		sq0[id].ins(valb[seq[i]],vala[seq[i]]*valb[seq[i]]);
		sq1[id].ins(valb[seq[i]],vala[seq[i]]*valb[seq[i]]);
	}
	sq0[id].upd(0);
	sq1[id].upd(0);
	return;
}
void updateone(ll x,ll v)
{
	vala[x]+=v;
	return;
}
void updatewhole(ll l,ll r,ll v)
{
	addsq[l/B]+=v;
	sq0[l/B].upd(-v);
	sq1[l/B].upd(-v);
	return;
}
ll query(ll l,ll r)
{
	return max(abs(sq0[l/B].qry(addsq[l/B])),abs(sq1[l/B].qry(addsq[l/B])));
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	ll i;
	scanf("%lld%lld",&n,&q);
	for(i=1;i<n;i++)
	{
		scanf("%lld",&par[i]);
		par[i]--;
		vt[par[i]].push_back(i);
	}
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		scanf("%lld",&b[i]);
	}
	cnt=-1;
	dfs(0);
	for(i=0;i<n;i++)
	{
		vala[din[i]]=suma[i];
		valb[din[i]]=abs(sumb[i]);
		seq[i]=i;
	}
	sort(seq,seq+n,cmp);
	for(i=0;i<n;i+=B)
	{
		rebuild(i,min(i+B,n)-1);
	}
	while(q--)
	{
		ll tp,x,y;
		scanf("%lld",&tp);
		if(tp==1)
		{
			scanf("%lld%lld",&x,&y);
			ll l=din[x-1],r=dout[x-1];
			for(i=(l/B)*B;i<n&&i/B==l/B;i++)
			{
				vala[i]+=addsq[i/B];
			}
			addsq[l/B]=0;
			for(i=l;i<=r&&i/B==l/B;i++)
			{
				updateone(i,y);
			}
			rebuild((l/B)*B,min((l/B+1)*B,n)-1);
			if(r/B==l/B)
			{
				continue;
			}
			for(i=l/B+1;i<r/B;i++)
			{
				updatewhole(i*B,(i+1)*B-1,y);
			}
			for(i=(r/B)*B;i<n&&i/B==r/B;i++)
			{
				vala[i]+=addsq[i/B];
			}
			addsq[r/B]=0;
			for(i=(r/B)*B;i<=r;i++)
			{
				updateone(i,y);
			}
			rebuild((r/B)*B,min((r/B+1)*B,n)-1);
		}
		else
		{
			scanf("%lld",&x);
			ll l=din[x-1],r=dout[x-1],ans=0;
			for(i=(l/B)*B;i<n&&i/B==l/B;i++)
			{
				vala[i]+=addsq[i/B];
			}
			addsq[l/B]=0;
			rebuild((l/B)*B,min((l/B+1)*B,n)-1);
			for(i=l;i<=r&&i/B==l/B;i++)
			{
				ans=max(ans,abs(vala[i])*valb[i]);
			}
			for(i=l/B+1;i<r/B;i++)
			{
				ans=max(ans,query(i*B,(i+1)*B-1));
			}
			if(l/B!=r/B)
			{
				for(i=(r/B)*B;i<n&&i/B==r/B;i++)
				{
					vala[i]+=addsq[i/B];
				}
				addsq[r/B]=0;
				rebuild((r/B)*B,min((r/B+1)*B,n)-1);
				for(i=(r/B)*B;i<=r;i++)
				{
					ans=max(ans,abs(vala[i])*valb[i]);
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}