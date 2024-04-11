#include<bits/stdc++.h>
//#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=4e5+10;
int n,m,h[M],p[M<<1],cnt,a[M],b[M],ans1[M],ans2[M],ans3[M],f[M],tag[M];
vector<pair<int,int> >v1[M],v2[M];
map<int,int>t;
struct segment_tree
{
	struct tree
	{
		int tl,tr,val,tag;
	}t[M<<4];
	#define l(x) t[(x)].tl
	#define r(x) t[(x)].tr
	#define val(x) t[(x)].val
	#define tag(x) t[(x)].tag
	#define lson k<<1
	#define rson k<<1|1
	void pushup(int k){val(k)=max(val(lson),val(rson));}
	void build(int k,int l,int r)
	{
		l(k)=l,r(k)=r,val(k)=0;
		if (l==r)return;
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
	}
	void update(int k,int l,int z)
	{
		if (tag(k))tag(k)=val(k)=0,tag(lson)=tag(rson)=1;
		if (l(k)>l||r(k)<l)return;
		if (l(k)==l&&r(k)==l){val(k)=max(z,val(k));return;}
		update(lson,l,z),update(rson,l,z);
		pushup(k);
	}
	int query(int k,int l,int r)
	{
		if (tag(k))tag(k)=val(k)=0,tag(lson)=tag(rson)=1;
		if (l(k)>=l&&r(k)<=r)return val(k);
		if (l(k)>r||r(k)<l)return 0;
		return max(query(lson,l,r),query(rson,l,r));
	}
	void clear(){tag(1)=1;}
}T;

signed main()
{
//	freopen("kite1.in","r",stdin);
//	freopen("kite1.txt","w",stdout);
	n=read(),m=read();
	for (int i=1;i<=n;i++)h[i]=p[i]=read();
	for (int i=1;i<=m;i++)a[i]=read(),b[i]=p[i+n]=read();
	sort(p+1,p+1+n+m);
	for (int i=1;i<=n+m;i++)
		if (p[i]!=p[i-1]||i==1)
			t[p[i]]=++cnt;
	for (int i=1;i<=n;i++)h[i]=t[h[i]];
	for (int i=1;i<=m;i++)b[i]=t[b[i]],v2[a[i]].pb(mp(b[i],i));
	T.build(1,1,cnt);
	for (int i=1;i<=n;i++)
		f[i]=T.query(1,1,h[i]-1)+1,
		T.update(1,h[i],f[i]),v1[f[i]].pb(mp(i,h[i]));
	T.clear();int ans=0,ss=0;
	for (int i=1;i<=n;i++)ans=max(ans,f[i]);
	for (int i=ans;i>=1;i--)sort(v1[i].begin(),v1[i].end());
	for (int i=1;i<=n;i++)
		if (f[i]==ans)ss++,tag[i]=1;
	for (int i=1;i<=n;i++)
			if (f[i]==ans)
				ans3[i]=(ss==1?ans-1:ans);
//	puts("qwq");
	for (int i=ans;i>=2;i--)
	{
		T.clear();int ss=0;
		for (int j=v1[i-1].size()-1,l=v1[i].size()-1;j>=0;j--)
		{
			while(l>=0&&v1[i][l].x>v1[i-1][j].x)
				T.update(1,v1[i][l].y,tag[v1[i][l].x]),l--;
			if (T.query(1,v1[i-1][j].y+1,cnt))
				tag[v1[i-1][j].x]=1,ss++;
		}
		if (ss==1)
		{
			for (int j=0;j<v1[i-1].size();j++)
				if (tag[v1[i-1][j].x])ans3[v1[i-1][j].x]=ans-1;
				else ans3[v1[i-1][j].x]=ans;
		}
		else
		{
			for (int j=0;j<v1[i-1].size();j++)
				ans3[v1[i-1][j].x]=ans;
		}
	}//puts("qwq");
//	for (int i=1;i<=n;i++)cout<<ans3[i]<<' ';
	T.clear();
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<v2[i].size();j++)
			ans1[v2[i][j].y]=T.query(1,1,v2[i][j].x-1);
		f[i]=T.query(1,1,h[i]-1)+1;
		T.update(1,h[i],f[i]);
	}T.clear();
	for (int i=n;i>=1;i--)
	{
		for (int j=0;j<v2[i].size();j++)
			ans2[v2[i][j].y]=T.query(1,v2[i][j].x+1,cnt);
		f[i]=T.query(1,h[i]+1,cnt)+1;
		T.update(1,h[i],f[i]);
	}
	for (int i=1;i<=m;i++)
		printf("%d\n",max(1+ans1[i]+ans2[i],ans3[a[i]]));
	return 0;
}