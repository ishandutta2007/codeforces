#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 100;

int a[N];
int cnt[N];

void solve(){
    int n, p, k;
    cin >> n >> p >> k;
    for(int i = 0 ; i <= n; i ++ ){
        cnt[i]=0;
    }
    char f;
    for(int i = 1; i <= n; i ++ ){
        cin >> f;
        a[i] = f - '0';
    }
    int x, y;
    cin >> x >> y;
    for(int i = p ; i <= n; i ++ ){
        cnt[i%k] += (a[i] == 0);
    }
    int sol = x * cnt[p % k];
    int cur = p;
    int tk = 0;
    while(cur < n){
        cnt[cur % k] -= (a[cur] == 0);
        cur ++ ;
        tk ++ ;
        sol = min(sol, x * cnt[cur % k] + tk * y);
    }
    cout << sol << "\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++ ){
        solve();
    }
    return 0;
}