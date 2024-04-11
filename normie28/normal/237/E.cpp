
// Problem : E. Build String
// Contest : Codeforces - Codeforces Round #147 (Div. 2)
// URL : https://codeforces.com/problemset/problem/237/E
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
#define ii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
const int maxN = 4e2;
typedef int i_N[maxN];
int N, M, sour, sink, flow[maxN][maxN], cap[maxN][maxN];
string t, s[maxN];
i_N A, B, P, L;
vector<int> adj[maxN];
 
bool found(int sour, int sink){
    priority_queue<ii, vector<ii>, greater<ii> > heap;
    heap.push(ii(0, sour));
    memset(P, 0, sizeof(P));
    P[sour] = -1;
    while(!heap.empty()){
        int u = heap.top().se, W = heap.top().fi; heap.pop();
        if(u == sink) return true;
        if(L[u] != W) continue;
        for(int v = 1; v <= sink; v++) if(flow[u][v] < cap[u][v]){
            int new_W = v <= N? v : 0;
            if(!P[v] || L[v] > max(new_W, W)){
                P[v] = u;
                L[v] = max(new_W, W);
                heap.push(ii(L[v], v));
            }
        }
    }
    return false;
}
 
void inc_flow(int sour, int sink){
    int max_flow = 1e9;
    for(int u = sink; P[u] != -1; u = P[u]) max_flow = min(max_flow, cap[P[u]][u] - flow[P[u]][u]);
    for(int u = sink; P[u] != -1; u = P[u]){
        flow[P[u]][u] += max_flow;
        flow[u][P[u]] -= max_flow;
    }
}
 
int main(){
	fio;
    cin >> t;
    for(int i = 'a'; i <= 'z'; i++)
        for(auto ch : t) B[i - 'a' + 1] += ch == i;
    cin >> N;
    M = 26;
    for(int i = 1; i <= N; i++) cin >> s[i] >> A[i];
    sour = N + M + 1;
    sink = N + M + 2;
    for(int i = 1; i <= N; i++) cap[sour][i] = A[i];
    for(int i = N + 1; i <= N + M; i++) cap[i][sink] = B[i - N];
    for(int i = 1; i <= N; i++){
        for(int j = 'a'; j <= 'z'; j++){
            int tmp = 0;
            for(auto ch : s[i]) tmp += ch == j;
            cap[i][j - 'a' + 1 + N] = tmp;
        }
    }
    while(found(sour, sink))
        inc_flow(sour, sink);
    int res = 0;
    for(int i = N + 1; i <= N + M; i++) if(flow[i][sink] < cap[i][sink]){
        cout << -1;
        return 0;
    }
    for(int i = 1; i <= N; i++) res += i * flow[sour][i];
    cout << res;
}