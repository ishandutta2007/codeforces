#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=8e5+20,mod = 1e9+7,inf=1e18,dlt = 12250,maxm = 2e6;
int poww(ll a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k&1))%mod;
}
int trie[N][28],cnt,n,num[N][2],h[N],par[N];
string s[N],t[N];
set<pll> st;
multiset<int> ms[N][2];
vector<int> mp[N][2];
void build(string v,bool f,int i){
    int p = 0;
    num[p][f]++;
    for(char u : v){
        int d = u-'a';
        if (!trie[p][d]){
            cnt++;
            h[cnt] = h[p]+1;
            trie[p][d] = cnt;
            par[cnt] = p;
        }
        p = trie[p][d];
        num[p][f]++;
    }
    mp[p][f].pb(i);
    int k = p;
    p = 0;
    ms[0][f].insert(k);
    for(char u : v){
        int d = u-'a';
        p = trie[p][d];
        ms[p][f].insert(k);
    }
    
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i,0,n){
        cin >> s[i];
        build(s[i],0,i+1);
    }
    rep(i,0,n){
        cin >> t[i];
        build(t[i],1,1+i);
    }
    rep(i,1,cnt+1)
        if (num[i][0] && num[i][1])
            st.insert({-h[i],i});
    int ans =0;
    vector<pll> out;
    rep(j,0,n){
        pll p = *(st.begin());
        ans -= p.X;
        int u=*(ms[p.Y][0].begin()),v=*(ms[p.Y][1].begin()),a,b;
        a = u;
        b = v;
        out.pb({u,v});
        while(u){
            auto it = ms[u][0].find(a);
            ms[u][0].erase(it);
            num[u][0]--;
            if (!num[u][0] && num[u][1])
                st.erase({-h[u],u});
            u = par[u];
        }
        while(v){
            auto it = ms[v][1].find(b);
            ms[v][1].erase(it);
            num[v][1]--;
            if (num[v][0] && !num[v][1])
                st.erase({-h[v],v});
            v = par[v];
        }
        auto it = ms[0][1].find(b);
        ms[0][1].erase(it);
        it = ms[0][0].find(a);
        ms[0][0].erase(it);
        num[0][1]--;
        num[0][0]--;
    }
    cout << ans << endl;
    for (pll p : out){
        cout << mp[p.X][0].back() << ' ' << mp[p.Y][1].back() << endl;
        mp[p.X][0].pop_back();
        mp[p.Y][1].pop_back();
    }
}