
// Problem : D. Binary String To Subsequences
// Contest : Codeforces - Codeforces Round #661 (Div. 3)
// URL : https://codeforces.com/contest/1399/problem/D
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
#define MAX_N 210
#define SIGMA 10
#define MLEN 1000010
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

 
int n, m, q, values[MAX_N*MAX_N];
int x[SIGMA], y[SIGMA], nxt[MAX_N*MAX_N];
 
bool in_cycle[MAX_N*MAX_N];
int vis[MAX_N*MAX_N], num_cyc=0, idx[MAX_N*MAX_N];
bool has[MAX_N*MAX_N][SIGMA], vis2[MAX_N*MAX_N];
int first_val[SIGMA];
 
vector<int> rev[MAX_N*MAX_N], cycles[MAX_N*MAX_N];
 
void dfs_cycles(int a) {
    if (vis[a]==2) return ;
    if (vis[a]==1) {
        in_cycle[a]=true;
        vis[a]=2;
        return ;
    }
    vis[a]=1;
    dfs_cycles(nxt[a]);
    vis[a]=2;
}
 
void getcycles() {
    memset(vis,0,sizeof(vis));
    memset(vis2,0,sizeof(vis2));
    memset(in_cycle,0,sizeof(in_cycle));
    memset(has,0,sizeof(has));
    for (int i=0; i<n; i++) {
        dfs_cycles(i);
        if (in_cycle[i] && !vis2[i]) {
            int j=i;
            do {
                in_cycle[j]=true;
                vis2[j]=true;
                idx[j]=num_cyc;
                has[num_cyc][values[j]]=true;
                cycles[num_cyc].push_back(j);
                j=nxt[j];
            } while (j!=i);
            num_cyc++;
        }
    }
}
 
void reverse_graph() {
    for (int i=0; i<n; i++) {
        if (!in_cycle[i]) {
            rev[nxt[i]].push_back(i);
        }
    }
}
 
bool dfs_query(int a, int pos, string& s) {
    if (pos<s.length() && values[a]==s[pos]-'0') pos++;
    if (pos==s.length()) return true;
    vis2[a]=true;
    for (auto val: rev[a]) {
        if (dfs_query(val,pos,s)) return true;
    }
    return false;
}
 
void query(string& s) {
    memset(vis2,0,sizeof(vis2));
    for (int i=0; i<n; i++) {
        if (in_cycle[i] && !vis2[i]) {
            int pos=-1;
            for (int j=0; j<SIGMA; j++) {
                if (first_val[j]!=-1 && !has[idx[i]][j]) {
                    if (pos==-1) pos=first_val[j];
                    else pos=min(pos,first_val[j]);
                }
            }
            if (pos==-1) {
                cout << "YES\n";
                return ;
            }
            for (int j: cycles[idx[i]]) {
                if (dfs_query(j,pos,s)) {
                    cout << "YES\n";
                    return ;
                }
            }
        }
    }
    cout << "NO\n";
}
 
int main(void) {
    char ex[MAX_N][MAX_N];
    cin >> n >> m >> q;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> ex[i][j];
            values[m*i+j]=ex[i][j]-'0';
        }
    }
    for (int i=0; i<SIGMA; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int ni=i+x[values[m*i+j]], nj=j+y[values[m*i+j]];
            if (ni<0 || nj<0 || ni>=n || nj>=m) {
                ni=i;
                nj=j;
            }
            nxt[m*i+j]=ni*m+nj;
        }
    }
    n*=m;
    getcycles();
    reverse_graph();
    for (int i=0; i<q; i++) {
        memset(first_val,-1,sizeof(first_val));
        string s="", t;
        cin >> t;
        for (int j=0; j<t.length(); j++) {
            s+=t[t.length()-1-j];
            first_val[t[j]-'0']=t.length()-1-j;
        }
        query(s);
    }
    return 0;
}