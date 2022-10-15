
// Problem : F. Rock-Paper-Scissors Champion
// Contest : Codeforces - Technocup 2019 - Elimination Round 4
// URL : https://codeforces.com/contest/1085/problem/F
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
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
   //     cout<<"updateK "<<node<<' '<<l<<' '<<r<<' '<<tar_l<<' '<<tar_r<<endl; 
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
    	if (l>r) return;
        updateK(1,1,tree_n,l,r,diff);
    }
    int_t getK(int_t node, int_t l, int_t r, int_t tar_l, int_t tar_r)
    {
 
  //      cout<<"getK "<<node<<' '<<l<<' '<<r<<' '<<tar_l<<' '<<tar_r<<endl; 
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
SegTree st[3];
int n,m,i,j,k,t,t1,u,v,a,b,res;
set<int> se[3];
map<char,int> mp;
int arr[200001];
string s;
void calc()
{
	res=0;
	for (int i=0;i<3;i++)
	{
		if (se[(i+1)%3].size()==0)
		res+=se[i].size();
		else if (se[(i+2)%3].size()==0)
		res+=0;
		else 
		{
			int l,r;
			l=*(se[(i+2)%3].begin());
			r=*(--se[(i+2)%3].end());
			res+=st[i].get(l,r);
			int u,v;
			u=*(se[(i+1)%3].begin());
			v=*(--se[(i+1)%3].end());
	//		cout<<i<<' '<<l<<' '<<r<<' '<<u<<' '<<v<<endl;
			res+=st[i].get(1,min(u,l)-1);
			res+=st[i].get(max(v,r)+1,n);
		}
	}
	cout<<res<<endl;
}
int main()
{
	fio;
	cin>>n>>m;
	cin>>s;
	for (i=0;i<3;i++)
	{
		st[i].reset(n);
	}
	mp['R']=0;
	mp['P']=1;
	mp['S']=2;
	for (i=1;i<=n;i++)
	{
		arr[i]=mp[s[i-1]];
		se[arr[i]].insert(i);
		st[arr[i]].update(i,i,1);
	}
	for (i=0;i<=m;i++)
	{
		if (i)
		{
			char c;
			cin>>a>>c;
			se[arr[a]].erase(a);
			st[arr[a]].update(a,a,-1);
			arr[a]=mp[c];
			se[arr[a]].insert(a);
			st[arr[a]].update(a,a,1);
		}
//		for (j=1;j<=n;j++) cout<<arr[j]<<' ';
		calc();
	}
}