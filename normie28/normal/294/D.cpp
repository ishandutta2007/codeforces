
// Problem : D. Shaass and Painter Robot
// Contest : Codeforces - Codeforces Round #178 (Div. 2)
// URL : https://codeforces.com/contest/294/problem/D
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
// p: x+y-1;
// m: y-x+n;
SegTree stp,stm;
ll arrp[200001],arrm[200001];
ll n,m,i,j,k,t,t1,u,v,a,b,x,y,newx,newy,curp,curm,res,cnt,iter,tar;
string s;
int main()
{
	fio;
	cin>>n>>m;
	res=1;
	cnt=0;
	cin>>x>>y>>s;
	if ((m*n)%2)
	{
		if ((x+y)%2) tar=(m*n)/2;
		else tar=m*n-(m*n/2);
	}
	else tar=m*n/2;
	stp.reset(m+n-1);
	stm.reset(m+n-1);
	while(true)
	{
		iter++;
		if (iter>1000000)
		{
			cout<<-1;
			return 0;
		}
		curp=x+y-1;
		curm=y-x+n;
	//	cout<<"iter="<<iter<<"\nx="<<x<<"\ny="<<y<<"\ns="<<s<<"\ncurp="<<curp<<"\ncurm="
	//	<<curm<<"\ncnt="<<cnt<<"\nres="<<res<<"\ntar="<<tar<<endl;
	//	for (i=1;i<=m+n-1;i++) cout<<arrp[i]<<' '; cout<<endl;
	//	for (i=1;i<=m+n-1;i++) cout<<arrm[i]<<' '; cout<<endl;
	//	cout<<"----------------------\n";
		if (s=="UL")
		{
			a=min(x-1,y-1);
			newx=x-a;
			newy=y-a;
			b=arrm[curm];
			if (b);
			else 
			{
				b=stp.get(curp-2*a,curp);
				cnt+=(a+1)-b;
			}
			if (cnt==tar)
			{
				for (i=curp-2*a;i<=curp;i+=2) if (!arrp[i]) break;
				res+=(curp-i)/2;
				cout<<res;
				return 0;
			}
			else
			{
				res+=a;
				if (a)
				{
				stm.update(curm,curm,1-arrm[curm]);
				arrm[curm]=1;
				}
				else cnt--;
				x=newx;
				y=newy;
				if ((x==1)and(y==1)) s="DR";
				else if (x==1) s="DL";
				else s="UR";
			}
		}
		else if (s=="DR")
		{
			a=min(n-x,m-y);
			newx=x+a;
			newy=y+a;
			b=arrm[curm];
			if (b);
			else 
			{
				b=stp.get(curp,curp+2*a);
				cnt+=(a+1)-b;
			}
			if (cnt==tar)
			{
				for (i=curp+2*a;i>=curp;i-=2) if (!arrp[i]) break;
				res+=(i-curp)/2;
				cout<<res;
				return 0;
			}
			else
			{
				res+=a;
				if (a)
				{
				stm.update(curm,curm,1-arrm[curm]);
				arrm[curm]=1;
				}
				else cnt--;
				x=newx;
				y=newy;
				if ((x==n)and(y==m)) s="UL";
				else if (x==n) s="UR";
				else s="DL";
			}
		}
		else if (s=="UR")
		{
			a=min(x-1,m-y);
			newx=x-a;
			newy=y+a;
			b=arrp[curp];
			if (b);
			else 
			{
				b=stm.get(curm,curm+2*a);
				cnt+=(a+1)-b;
			}
			if (cnt==tar)
			{
				for (i=curm+2*a;i>=curm;i-=2) if (!arrm[i]) break;
				res+=(i-curm)/2;
				cout<<res;
				return 0;
			}
			else
			{
				res+=a;
				if (a)
				{
				stp.update(curp,curp,1-arrp[curp]);
				arrp[curp]=1;
				}
				else cnt--;
				x=newx;
				y=newy;
				if ((x==1)and(y==m)) s="DL";
				else if (x==1) s="DR";
				else s="UL";
			}
		}
		else if (s=="DL")
		{
			a=min(n-x,y-1);
			newx=x+a;
			newy=y-a;
			b=arrp[curp];
			if (b);
			else 
			{
				b=stm.get(curm-2*a,curm);
				cnt+=(a+1)-b;
			}
			if (cnt==tar)
			{
				for (i=curm-2*a;i<=curm;i+=2) if (!arrm[i]) break;
				res+=(curm-i)/2;
				cout<<res;
				return 0;
			}
			else
			{
				res+=a;
				if (a)
				{
				stp.update(curp,curp,1-arrp[curp]);
				arrp[curp]=1;
				}
				else cnt--;
				x=newx;
				y=newy;
				if ((x==n)and(y==1)) s="UR";
				else if (x==n) s="UL";
				else s="DR";
			}
		}
	}
}