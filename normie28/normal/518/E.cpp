
// Problem : E. Arthur and Questions
// Contest : Codeforces - Codeforces Round #293 (Div. 2)
// URL : https://codeforces.com/problemset/problem/518/E
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
const int N=200010;
#define int long long
const int mod=LLONG_MAX;
int n,k;
string c[N];
int a[N];
signed main(){
    cin>>n>>k;
    for(int i=0;i<n;i++) {
        cin>>c[i];
        if(c[i]!="?")a[i]=stoi(c[i]);
    }
 
    for(int i=0;i<k;i++){
        int old=-mod, cnt=0, j,what,ii;
        for(j=i;j<n;j+=k){
            if(c[j]=="?") cnt++;
            else if(cnt){
                if(a[j]-cnt<old){
                    cout<<"Incorrect sequence";
                    return 0;
                }
                if(a[j]>cnt && old<0) {
                    what=-(cnt>>1);
                    if(what <= old) what = old+1;
                }
                else if(old>=0) what=old+1;
                else if(a[j]-cnt<=0) what=a[j]-cnt;
                int ii=j-(cnt*k);
                if(ii>=0) for(;c[ii]=="?";ii+=k,what++) a[ii]=what;
 
                cnt=0;
                old=a[j];
            }
            else old=a[j];
        }
        if(cnt){
            int now;
            now=mod;
            if(old<0) {
                what=-(cnt>>1);
                while(what<=old) what++;
            }
            else if(old>=0) what=old+1;
            else if(now<=0) what=now;
            ii=j-(cnt*k);
            if(ii>=0) for(;c[ii]=="?";ii+=k,what++)
                    a[ii]=what;
 
        }
    }
 
    for(int j=0;j<k;j++) for(int i=j+k;i<n;i+=k) if(a[i]<=a[i-k]) {
        cout<<"Incorrect sequence";
        return 0;
    }
    for(int i=0;i<n;i++) cout<<a[i]<<' ';
}