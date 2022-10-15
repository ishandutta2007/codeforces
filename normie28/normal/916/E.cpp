/*
	Normie's Template v2.0
*/
 
// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;
 
// ordered_set library.
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set(el) tree<el,null_type,less<el>,rb_tree_tag,tree_order_statistics_node_update>
 
// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
//#include <atcoder/all>
//using namespace atcoder;
 
//Pragmas (Comment out these three lines if you're submitting in szkopul.)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
//File I/O.
#define FILE_IN "sample.inp"
#define FILE_OUT "sample.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
 
//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define endl "\n"
 
//Order checking.
#define ord(a,b,c) ((a>=b)and(b>=c))
 
//min/max redefines, so i dont have to resolve annoying compile errors.
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

//Constants.
#define MOD (ll(998244353))
#define MAX 300001
#define mag 320
 
//Pairs and 3-pairs.
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pii(element_type) pair<element_type,element_type>
#define piii(element_type) pair<element_type,pii(element_type)>
 
//Quick power of 2.
#define pow2(x) (ll(1)<<x)
 
//Short for-loops.
#define ff(i,__,___) for(int i=__;i<=___;i++)
#define rr(i,__,___) for(int i=__;i>=___;i--)
 
//Typedefs.
#define bi BigInt
typedef long long ll;
typedef long double ld;
typedef short sh;
//---------END-------//
typedef long long int_t; // Element type
int_t star[1000001];
struct SegTree
{
    int_t lazy[4000004],val[4000004]; //Contains the current value of each node, as well as the lazy propagation amount stored.
    int_t tree_n;
    void resetK (int_t node, int_t l, int_t r) // Resets the tree nodes. 
    {
        if (l==r) 
        {
            lazy[node]=0;
            val[node]=star[l];
        }
        else
        {
            int_t mid=(l+r)/2;
            resetK(node<<1,l,mid);
            resetK((node<<1)+1,mid+1,r);
            lazy[node]=0;
            val[node]=val[node<<1]+val[(node<<1)+1];
        }
    }
    void reset(int_t n)
    {
        resetK(1,1,n);
        tree_n=n;
    }
    void flusha(int_t node, int_t l, int_t r)
    {
        lazy[node<<1]+=lazy[node];
        lazy[(node<<1)+1]+=lazy[node];
        int_t mid=(l+r)/2;
        val[node<<1]+=lazy[node]*(mid-l+1);
        val[(node<<1)+1]+=lazy[node]*(r-(mid+1)+1);
        lazy[node]=0;
    }
    void updateK(int_t node, int_t l, int_t r, int_t tar_l, int_t tar_r, int_t diff)
    {
      //  cout<<"updateK "<<node<<' '<<l<<' '<<r<<' '<<tar_l<<' '<<tar_r<<endl; 
        if ((l>tar_r)or(r<tar_l)) return;
        else if ((l>=tar_l)and(r<=tar_r))
        {
            lazy[node]+=diff;
            val[node]+=diff*(r-l+1);
        }
        else
        {
            flusha(node,l,r);
            int_t mid=(l+r)/2;
            updateK(node<<1,l,mid,tar_l,tar_r,diff);
            updateK((node<<1)+1,mid+1,r,tar_l,tar_r,diff);
            val[node]=val[node<<1]+val[(node<<1)+1];
        }
        
    }
    void update(int_t l, int_t r, int_t diff)
    {
    	if (l>r) return ;
        updateK(1,1,tree_n,l,r,diff);
    }
    int_t getK(int_t node, int_t l, int_t r, int_t tar_l, int_t tar_r)
    {
 
     //   cout<<"getK "<<node<<' '<<l<<' '<<r<<' '<<tar_l<<' '<<tar_r<<endl; 
        if ((l>tar_r)or(r<tar_l)) return 0;
        else if ((l>=tar_l)and(r<=tar_r))
        {
            return val[node];
        }
        else
        {
            flusha(node,l,r);
            int_t mid=(l+r)/2;
            int_t aa; aa=getK(node<<1,l,mid,tar_l,tar_r);
            int_t bb; bb=getK((node<<1)+1,mid+1,r,tar_l,tar_r);
            return aa+bb;
        }
        
    }
    int_t get(int_t l, int_t r)
    {
    	if (l>r) return 0;
        return getK(1,1,tree_n,l,r);
    }
};
SegTree st;
vector<ll> gt[100001],gtd[100001];
ll l[100001],r[100001],dep[100001];
ll lt[100001],rt[100001];
ll spa[200001][20];
ll anc[200001][20];
vector<ll> lis;
ll arr[200001];
ll n,m,i,j,k,t,t1,u,v,a,b,c,q,root;
void dfs(ll x, ll d, ll p)
{
	dep[x]=d;
	lis.push_back(x);
	t++;
	lt[x]=t;
	l[x]=lis.size();
	anc[x][0]=p;
	for (ll i=1;i<20;i++) anc[x][i]=anc[anc[x][i-1]][i-1];
	for (ll g : gt[x]) if (!l[g]) {dfs(g,d+1,x); lis.push_back(x);}
	r[x]=lis.size();
	rt[x]=t;
}
ll lca (ll a, ll b)
{
	ll le=l[a];
	ll ri=l[b];
	if (le>ri) swap(le,ri);
	ll sz=floor(log2(ri-le+1));
	ll u=spa[le][sz];
	ll v=spa[ri-(1<<sz)+1][sz];
//	cout<<"lcaing: "<<a<<' '<<b<<endl;
//	cout<<"cands: "<<u<<' '<<v<<endl;
	if (dep[u]<dep[v]) return u;
	else return v;
}
void upd (ll x, ll y)
{
//	cout<<"upd "<<x<<' '<<y<<' '<<root<<endl;
	if (x==root) st.update(1,n,y); else
	if ((lt[x]<lt[root])and(lt[root]<=rt[x]))
	{
		ll u=root;
		for (ll i=19;i>=0;i--) if ((lt[x]<lt[anc[u][i]])and(lt[anc[u][i]]<=rt[x])) u=anc[u][i];
		st.update(1,lt[u]-1,y);
		st.update(rt[u]+1,n,y);
	}
	else
	{
		st.update(lt[x],rt[x],y);
	}
}
ll ge (ll x)
{
//	cout<<"get "<<x<<' '<<root<<endl;
	if (x==root) return st.get(1,n); else
	if ((lt[x]<lt[root])and(lt[root]<=rt[x]))
	{
		ll u=root;
		for (ll i=19;i>=0;i--) if ((lt[x]<lt[anc[u][i]])and(lt[anc[u][i]]<=rt[x])) u=anc[u][i];
		return st.get(1,lt[u]-1)+
		st.get(rt[u]+1,n);
	}
	else
	{
		return st.get(lt[x],rt[x]);
	}
}
int main()
{
//	ofile;
    fio;
	cin>>n>>q;
	for (i=1;i<=n;i++) cin>>arr[i];
	for (i=1;i<n;i++)
	{
		cin>>u>>v;
		gt[u].push_back(v);
		gt[v].push_back(u);
	}
	
	dfs(1,1,1);
	for (j=0;j<20;j++) for (i=1;i<=2*n-1;i++)
	{
		if (j==0) spa[i][j]=lis[i-1];
		else
		{
			spa[i][j]=spa[i][j-1];
			if ((i+(1<<(j-1))<=2*n-1)and(dep[spa[i][j]]>dep[spa[i+(1<<(j-1))][j-1]])) 
			spa[i][j]=spa[i+(1<<(j-1))][j-1];
		}
	}
	for (i=1;i<=n;i++) star[lt[i]]=arr[i];
	root=1;
	st.reset(n);
	for (i=1;i<=q;i++)
	{
		cin>>t;
		if (t==1)
		{
			cin>>v;
			root=v;
		}
		else if (t==2)
		{
			cin>>a>>b>>c;
			ll c1=lca(a,b);
			ll c2=lca(b,root);
			ll c3=lca(root,a);
	//		cout<<c1<<' '<<c2<<' '<<c3<<endl;
			if ((dep[c1]>=dep[c2])and(dep[c1]>=dep[c3])) upd(c1,c);
			else
			
			if ((dep[c2]>=dep[c1])and(dep[c2]>=dep[c3])) upd(c2,c);
			else
			
			if ((dep[c3]>=dep[c1])and(dep[c3]>=dep[c2])) upd(c3,c);
			
		}
		else if (t==3)
		{
			cin>>a;
			cout<<ge(a)<<endl;
		}
//		cout<<endl;
	}
	/*
	*/
}