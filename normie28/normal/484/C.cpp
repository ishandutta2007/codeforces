
// Problem : C. Strange Sorting
// Contest : Codeforces - Codeforces Round #276 (Div. 1)
// URL : https://codeforces.com/problemset/problem/484/C
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
const int SIZE = 1e6+5;
char s[SIZE],nxt[SIZE];
int n;
vector<int>qq[SIZE];
int from[SIZE],used[SIZE],tt,No;
pair<int,int>be[SIZE];
void go(int k,int d){
    int tmp=0;
    for(int i=0;i<d;i++){
        for(int j=i;j<k;j+=d)from[tmp++]=j+1;
    }
    from[k]=0;
    tt++;
    No=0;
    for(int i=0;i<=k;i++){
        if(used[i]==tt)continue;
        qq[No].clear();
        int now=i;
        while(used[now]!=tt){
            be[now]=make_pair(No,qq[No].size());
            used[now]=tt;
            qq[No].push_back(now);
            now=from[now];
        }
        No++;
    }
    int all=n-k+1;
    for(int i=0;i<n;i++){
        if(i<k){
            if(be[i+1].first==0){
                if(be[i+1].second>=all)nxt[n-k+qq[0][be[i+1].second-all]]=s[i];
                else nxt[be[i+1].second-1]=s[i];
            }
            else{
                int me=be[i+1].first;
                nxt[n-k+qq[me][((be[i+1].second-all)%(int)qq[me].size()+(int)qq[me].size())%(int)qq[me].size()]]=s[i];
            }
        }
        else{
            all=n-i;
            if(be[k].first==0){
                if(be[k].second>=all)nxt[n-k+qq[0][be[k].second-all]]=s[i];
                else nxt[i-k+1+be[k].second-1]=s[i];
            }
            else{
                int me=be[k].first;
                nxt[n-k+qq[me][((be[k].second-all)%(int)qq[me].size()+(int)qq[me].size())%(int)qq[me].size()]]=s[i];
            }
            
        }
    }
    puts(nxt);
    strcpy(s,nxt);
}
int main(){
    fio;
	cin>>s;
    n=strlen(s);
    int m;
    cin>>m;
    while(m--){
        int k,d;
        cin>>k>>d;
        go(k,d);
    }
}