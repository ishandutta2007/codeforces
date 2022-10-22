#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vb vector<bool>
#define ii pair<int,int>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18, MOD=1e9+7;
const int AZ = 'n'-'a'+1;
const int MAXSZ = 1e3 + 5;
struct AHO{
    int n;
    int g[MAXSZ][AZ];
    int link[MAXSZ];
    int val[MAXSZ];
    AHO():n(1){
        init(0);
    }
    inline void init(int i){
        val[i] = 0;
        loop(c,0,AZ) g[i][c] = -1;
    }
    void add(string& s, int x){
        int cur = 0;
        for(char c:s){
            if (g[cur][c]==-1){
                g[cur][c] = n;
                init(n++);
            }
            cur = g[cur][c];
        }
        val[cur]+=x;
    }
    void create_link(){
        link[0] = -1;
        queue<int> q; q.push(0);
        while(q.size()){
            int v = q.front(); q.pop();
            loop(c,0,AZ){
                if (g[v][c]==-1) continue;
                int u = g[v][c];
                int j = link[v];
                while(j!=-1 && g[j][c]==-1) j = link[j];
                if (j!=-1) link[u] = g[j][c];
                else link[u] = 0;
                val[u] += val[link[u]];
                q.push(u);
            }
        }
    }
    int next_state(int cur, char c){
        if (cur==-1) return 0;
        if (g[cur][c]!=-1) return g[cur][c];
        return g[cur][c] = next_state(link[cur], c);
    }
};
AHO aho;
string s;
int feed(int &cur, int st, int en){//st and en includes
    int ans = 0;
    loop(i,st,en+1){
        cur = aho.next_state(cur, s[i]);
        ans += aho.val[cur];
    }
    return ans;
}

const int N = 1<<AZ;
int n,sz;
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    int k; cin>>k;
    loop(i,0,k){
        int v; cin>>s>>v;
        for(char &c:s) c-='a';
        aho.add(s,v);
    }
    aho.create_link();
    cin>>s;
    n = s.size();
    vi pos(1,0);
    loop(i,0,n) if (s[i]=='?') pos.pb(i+1), s[i] = -1;
                else s[i]-='a';
    pos.pb(n+1);
    sz = aho.n;
    int m = pos.size();
    int dp[MAXSZ][N], next[MAXSZ][N];
    loop(i,0,sz) loop(j,0,N) dp[i][j] = next[i][j] = -INF;
    dp[0][0] = 0;
    int ans = -INF;
    int tmp = 0;
    loop(i,0,m-1){
        ans = -INF;
        loop(state,0,sz){
            bool b = 0;
            loop(mask,0,N) if (dp[state][mask]>=-INF/2) b = 1;
            if (!b) continue;
            int cur = state;
            int dv = feed(cur,pos[i], pos[i+1]-2);
            loop(mask,0,N){
                chkmax(ans, dp[state][mask] + dv);
                loop(c,0,AZ){
                    if (mask & (1<<c)) continue;
                    if (dp[state][mask]<=-INF/2) continue;
                    int ns = aho.next_state(cur, c);
                    chkmax(next[ns][mask | (1<<c)], 
                           dp[state][mask] + dv + aho.val[ns]);
                }
            }
        }
        loop(i,0,sz) loop(j,0,N) dp[i][j] = next[i][j], next[i][j] = -INF;
    }
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ g.cpp -o a & a
2
aaa 10
aab 20
aaa?
*/