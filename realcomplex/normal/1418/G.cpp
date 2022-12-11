#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = (int)5e5 + 100;
const ll mod = (ll)3e18 - 95;

ll ass[N];
int c[N];
vector<int> Q[N];
ll idx[N];

int main(){
    fastIO;
    int n;
    cin >> n;
    for(int i = 0 ; i <= n; i ++ ){
        ass[i] = ((ll)rng() % mod + mod) % mod;
    }
    int x;
    map<ll, ll> cnt;
    int ban = 0;
    int mx = 0;
    ll answ = 0;
    cnt[0] ++ ;
    for(int i = 1; i <= n; i ++ ){
        cin >> x;
        Q[x].push_back(i);
        idx[i] = idx[i - 1];
        idx[i] ^= c[x] * ass[x];
        c[x] ++ ;
        c[x] %= 3;
        idx[i] ^= c[x] * ass[x];
        if(Q[x].size() >= 4)
            mx = max(mx, Q[x][Q[x].size() - 4]);
        while(ban < mx){
            cnt[idx[ban]] -- ;
            ban ++ ;
        }
        answ += cnt[idx[i]];
        cnt[idx[i]] ++ ;
    }
    cout << answ << "\n";
    return 0;
}