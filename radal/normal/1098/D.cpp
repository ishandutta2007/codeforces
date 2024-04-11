#include <bits/stdc++.h>
#pragma GCC optimize("O3")
//#pragma GCC target("avx2,fma")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
const long long int N = 5e5+20,mod = 1e9+7,inf = 1e18+10,sq = 300,maxm= 700+2;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}

inline int poww(int a,int k){
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k >>= 1;
    }
    return z;
}
pair<char,int> Q[N];
ll fen[N];
int q;
map<int,vector<int>> mp;
inline void upd(int r,int x){
    for (; r < q; r |= (r+1)) fen[r] += x;
}
inline ll que(int l){
    ll ans = 0;
    for (; l >= 0; l = (l&(l+1)) - 1)
        ans += fen[l];
    return ans;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> q;
    vector<pll> ve;
    rep(i,0,q){
        cin >> Q[i].X >> Q[i].Y;
        if (Q[i].X == '+'){
            ve.pb({Q[i].Y,i});
            mp[Q[i].Y].pb(i);
        }
        else{
            ve.pb({Q[i].Y,mp[Q[i].Y].back()});
            mp[Q[i].Y].pop_back();
        }
    }
    rep(i,0,q) mp[Q[i].Y].clear();
    sort(ve.begin(),ve.end());
    set<int> st,can;
    rep(i,0,q){
        int ind;
        if (Q[i].X == '+') ind = lower_bound(ve.begin(),ve.end(),make_pair(Q[i].Y,i))-ve.begin();
        else{
            ind = lower_bound(ve.begin(),ve.end(),make_pair(Q[i].Y,mp[Q[i].Y].back()))-ve.begin();
            mp[Q[i].Y].pop_back();
        }
        if (Q[i].X == '+'){
            mp[Q[i].Y].pb(i);
            st.insert(ind);
            upd(ind,Q[i].Y);
            auto it = st.find(ind);
            it++;
            if (it != st.end()){
                int j = (*it);
                if (ve[j].X <= Q[i].Y*2){
                    can.erase(j);
                }
            }
            it--;
            if (it == st.begin()) can.insert(ind);
            else{
                it--;
                int j = (*it);
                if (ve[j].X*2< Q[i].Y) can.insert(ind);
            }
        }
        else{
            can.erase(ind);
            upd(ind,-Q[i].Y);
            auto it = st.find(ind);
            int pr = -1;
            if (it != st.begin()){
                it --;
                pr = (*it);
                it++;
            }
            it++;
            if (it != st.end()){
                int j = (*it);
                if (pr == -1 || ve[j].X > ve[pr].X*2) can.insert(j);
            }
            st.erase(ind);
        }
        int ans = st.size();
        for ( int u : can){
            if (que(u-1)*2 <  ve[u].X) ans--;
        }
        cout << ans << endl;
    }
}