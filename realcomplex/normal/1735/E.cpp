#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 1050;
vector<int> T[2][N];

bool vis[2][N];

vector<pii> na;
vector<pii> nb;
int li, ri;
vector<int> pp;
void dfs(int u, int b){
    vis[b][u]=true;
    int low;
    for(auto x : T[b][u]){
        if(vis[1-b][x]){
            continue;
        }
        if(b == 0){
            low = min(na[u].se, nb[x].se);
            na[u].se -= low;
            nb[x].se -= low;
            if(abs(li - na[u].fi - ri) == nb[x].fi){
                for(int v = 0; v < low; v ++ ){
                    pp.push_back(li - na[u].fi);
                }
            }
            else{
                for(int v = 0; v < low; v ++ ){
                    pp.push_back(li + na[u].fi);
                }
            }
        }
        else{
            low = min(nb[u].se, na[x].se);
            nb[u].se -= low;
            na[x].se -= low;
            if(abs(li - na[x].fi - ri) == nb[u].fi){
                for(int v = 0; v < low; v ++ ){
                    pp.push_back(li - na[x].fi);
                }
            }
            else{
                for(int v = 0; v < low; v ++ ){
                    pp.push_back(li + na[x].fi);
                }
            }
        }
        dfs(x, 1-b);
    }
}

void add_edge(int i, int j){
    T[0][i].push_back(j);
    T[1][j].push_back(i);
}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0 ; i < n; i ++ ){
        cin >> a[i];
    }
    for(int i = 0 ; i < n; i ++ ){
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<pii> ca;
    vector<pii> cb;
    for(auto x : a){
        if(ca.empty() || x != ca.back().fi){
            ca.push_back(mp(x, 1));
        }
        else{
            ca.back().se ++ ;
        }
    }
    for(auto x : b){
        if(cb.empty() || x != cb.back().fi){
            cb.push_back(mp(x, 1));
        }
        else{
            cb.back().se ++ ;
        }
    }
    sort(ca.begin(), ca.end());
    sort(cb.begin(), cb.end());
    li = 0;
    int i1, i2;
    int w1, w2;
    for(auto x : ca){
        for(int q = -1; q <= 1; q += 2){
            for(int p = -1; p <= 1; p += 2){
                ri = li + q * x.fi + p * b[n - 1];
                for(int i = 0 ; i < n; i ++ ){
                    T[0][i].clear();
                    T[1][i].clear();
                }
                for(int i = 0 ; i < ca.size(); i ++ ){

                    w1 = abs(li - ca[i].fi - ri);
                    w2 = abs(li + ca[i].fi - ri);
                    i1 = lower_bound(cb.begin(), cb.end(), mp(w1,0)) - cb.begin();
                    i2 = lower_bound(cb.begin(), cb.end(), mp(w2,0)) - cb.begin();
                    if(i1 >= cb.size() || cb[i1].fi != w1) i1 = -1;
                    if(i2 >= cb.size() || cb[i2].fi != w2) i2 = -1;
                    if(i1 != -1){
                        add_edge(i, i1);
                    }
                    if(i2 != -1 && i2 != i1){
                        add_edge(i, i2);
                    }
                    /*
                    for(int j = 0 ;j < cb.size(); j ++ ){
                        if(w1 == cb[j].fi || w2 == cb[j].fi){
                            T[0][i].push_back(j);
                            T[1][j].push_back(i);
                            cout << i << " -> " << j << "\n";
                        }
                    }
                    cout << "\n";
                    return;
                    */

                }
                for(int i = 0 ; i < n; i ++ ){
                    vis[0][i]=vis[1][i]=false;
                }
                na = ca;
                nb = cb;
                pp.clear();
                for(int i = 0 ; i < ca.size(); i ++ ){
                    if(!vis[0][i] && T[0][i].size() == 1){
                        dfs(i, 0);
                    }
                }
                for(int i = 0 ; i < cb.size(); i ++ ){
                    if(!vis[1][i] && T[1][i].size() == 1){
                        dfs(i, 1);
                    }
                }
                if(pp.size() == n){
                    cout << "YES\n";
                    int low = 0;
                    low = min(low, li);
                    low = min(low, ri);
                    for(auto yi : pp) low = min(low, yi);
                    li -= low;
                    ri -= low;
                    for(auto yi : pp){
                        cout << yi - low << " ";
                    }
                    cout << "\n";
                    cout << li << " " << ri << "\n";
                    return;
                }
            }
        }
    }
    cout << "NO\n";
}
int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}