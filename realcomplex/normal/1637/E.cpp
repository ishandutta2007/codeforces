#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)3e5 + 10;

vector<int> V[N];
map<int, int> cnt;
map<pii, int> E;
int A[N];


void solve(){
    int n, m;
    cin >> n >> m;
    cnt.clear();
    E.clear();
    for(int i = 1; i <= n; i ++ ){
        V[i].clear();
    }
    for(int i = 1; i <= n; i ++ ){
        cin >> A[i];
        cnt[A[i]] ++ ;
    }
    for(auto x : cnt){
        V[x.se].push_back(x.fi);
    }
    int x, y;
    for(int i = 1; i <= m; i ++ ){
        cin >> x >> y;
        E[mp(x,y)]=1;
        E[mp(y,x)]=1;
    }
    int yi;
    ll res = 0;
    for(int i = 1; i <= n; i ++ ){
        for(auto x : V[i]){
            for(int j = 1; j <= i ; j ++ ){
                for(int yi = (int)V[j].size() - 1; yi >= 0; yi -- ){
                    y = V[j][yi];
                    if(x == y) continue;
                    if(E.count(mp(x, y))) continue;
                    res = max(res, (x + y) * 1ll * (i + j));
                    break;
                }
            }
        }
    }
    cout << res << "\n";



}

int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    int tc;
    cin >> tc;
    for (int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}