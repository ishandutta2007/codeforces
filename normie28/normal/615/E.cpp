
// Problem : E. Hexagons
// Contest : Codeforces - Codeforces Round #338 (Div. 2)
// URL : https://codeforces.com/problemset/problem/615/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
int main()
{
    int64_t i,j,n,m,sum,t,t1,x,y,cycle,pos,xcur,ycur,cur,d2,cb,cr,k,lol,bot,mid,top;
    const int64_t d[6][2]= {{-1,2},{-2,0},{-1,-2},{1,-2},{2,0},{1,2}};
    t=1; 
    for (t1=1;t1<=t;t1++) {
    	bot=2;top=1000000000;
    	mid=(bot+top)/2;
    	cin>>n;
    	if (n==0) cout<<0<<' '<<0;
    	else 
    	{
    		n++; 
    		cycle=2; 
    		while (!((1+3*(mid-1)*(mid-2)<n)and(1+3*(mid)*(mid-1)>=n))) 
    			{
    				if (1+3*(mid)*(mid-1)<n) 
    				{bot=mid; mid=(bot+top)/2;} 
    				else 
    				{top=mid; mid=(bot+top)/2;}
    			}
    			cycle=mid;
    			pos=n-(1+3*(cycle-1)*(cycle-2));
    			cur=0; 
    			xcur=(cycle-1)*2; ycur=0; k=0;
    			while (cur<pos) 
    			{
    				if (cur+(cycle-1)<=pos) 
    				{
    					xcur+=d[k][0]*(cycle-1);
    					ycur+=d[k][1]*(cycle-1); 
    					cur+=cycle-1; k++;
    				}
    			else { 
    				{
    					xcur+=d[k][0]*(pos-cur);
    					ycur+=d[k][1]*(pos-cur);
    				} 
    				cur=pos;
    			}
    	}
    	cout<<xcur<<' '<<ycur;
	}
    cout<<endl;
	}
}