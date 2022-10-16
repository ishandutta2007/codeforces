#include <bits/stdc++.h>
#include <random>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
#define ull unsigned long long

using namespace std;

const int nax = 2e5 + 5;
ll b[nax];
ll n;
ll a[nax];
void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> b[i];
    ll one = n * (n + 1) / 2;
    ll sum = 0;
    for(int i=1;i<=n;i++) sum += b[i];
    if(sum % one != 0){
        cout << "NO" << "\n";
        return;
    }
    ll cnt = sum / one;
    for(int i=1;i<=n;i++){
        int last = i - 1;
        if(last == 0) last = n;
        ll more = b[i] - b[last];
        more = -more;
        ll xd = more + cnt;
        if(abs(xd) % n != 0){
            cout << "NO" << "\n";
            return;
        }
        a[i] = xd / n;
    }
    bool wa = false;
    for(int i=1;i<=n;i++){
        if(a[i] <= 0) wa = true;
    }
    if(wa){
        cout << "NO" << "\n";
        return;
    }
    cout << "YES" << "\n";
    for(int i=1;i<=n;i++) cout << a[i] << " ";
    cout << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}