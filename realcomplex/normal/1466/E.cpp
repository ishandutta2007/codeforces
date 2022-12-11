#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)5e5 + 100;
const ll MOD = (int)1e9 + 7;
const int LOG = 60;

ll x[N];
ll p[N];
ll q[N];
int cnt[LOG];

void add(ll &x, ll y){
    x += y;
    x %= MOD;
}

void solve(){
    int n;
    cin >> n;
    for(int i =0 ; i < LOG; i ++ ){
        cnt[i] = 0;
    }
    for(int i = 1; i <= n; i ++ ){
        cin >> x[i];
        for(int j = 0 ; j < LOG; j ++ ){
            if((x[i] & (1ll << j))){
                cnt[j]++;
            }
        }
    }
    ll pw;
    ll soln = 0;
    for(int i = 1; i <=n; i ++ ){
        p[i]=q[i]=0;
        for(int j = 0 ; j < LOG; j ++ ){
            pw = (1ll << j) % MOD;
            if((x[i] & (1ll << j))){
                add(p[i], cnt[j]*1ll*pw);
                add(q[i], n*1ll*pw);
            }
            else{
                add(q[i],cnt[j]*1ll*pw);
            }
        }
        add(soln,p[i]*1ll*q[i]);
    }
    cout << soln << "\n";
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