
// Problem : E. Tractor College
// Contest : Codeforces - Codeforces Round #126 (Div. 2)
// URL : https://codeforces.com/problemset/problem/200/E
// Memory Limit : 256 MB
// Time Limit : 4000 ms
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
#define fef(i,a,b) for(ll i=a;i<=b;i++)
#define rer(i,a,b) for(ll i=b;i>=a;i--)
#define wew while(true)
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
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int inf = ~0u>>2;
int c3,c4,c5,k3,k4,k5;
int F(){
    return abs(c3*k3-c4*k4)+abs(c4*k4-c5*k5);
}
int main()
{
    int n,s,i,j,k;
    cin>>n>>s;
    for(c3=c4=c5=0;n;n--)
    {
    	cin>>j;
        if(j==3) c3++;
        if(j==4) c4++;
        if(j==5) c5++;
    }
    int res=inf,x,y,z;
    for(k3=s/(c3+c4+c5);k3>=0;k3--)
    {
        int up=inf;
        for(k4=(s-k3*c3)/(c4+c5);k4>=k3;k4--)
        {
            k5=(s-c3*k3-k4*c4);if(k5%c5) continue;
            k5/=c5;
            if(k5<k4 ) continue;
            int tmp=F();
            if(tmp<up)
            { 
                up=tmp;
                if(up<res)
                {
                    res=up;
                    x=k3;y=k4;z=k5;
                }
            }
            else break;
        }
    }
    if(res==inf) cout<<-1;
    else cout<<x<<' '<<y<<' '<<z;
}