
// Problem : C. Little Elephant and Shifts
// Contest : Codeforces - Codeforces Round #136 (Div. 1)
// URL : https://codeforces.com/problemset/problem/220/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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
const int N=100005;
int a[N],b[N],posa[N],posb[N];
set<pair<int,int> > pd,nd;
int main(){
    int n,i;
    cin>>n;
    for(i=1;i<=n;i++){
    	cin>>a[i];
        posa[a[i]]=i;
    }
    for(i=1;i<=n;i++){
    	cin>>b[i];
        posb[b[i]]=i;
    }
    for(i=1;i<=n;i++){
        int diff=abs(posb[i]-posa[i]);
        if(posb[i]>=posa[i])
            pd.insert({diff,i});
        else
            nd.insert({diff,i});
    }
    for(i=0;i<n;i++){
        while(pd.size() >0 && pd.begin()->first < i){
            nd.insert({1-i,pd.begin()->second});
            pd.erase(pd.begin());
        }
        if(i>0){
            int x=b[i];
            if(posb[x]<posa[x])
                nd.erase({posa[x]-posb[x],x});
            else
                nd.erase({1-(posb[x]-posa[x]+1),x});
            pd.insert({n-posa[x]+i,x});
        }
        cout<<min(pd.begin()->first -i, nd.begin()->first+i)<<endl;
    }
}