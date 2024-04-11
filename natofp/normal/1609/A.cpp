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

ll a[22];

void solve(){
    int n; cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    int id = -1;
    int best = 0;
    for(int i=1;i<=n;i++){
        int tmp = a[i];
        while(tmp % 2 == 0) tmp /= 2;
        if(tmp > best){
            best = tmp;
            id = i;
        }
    }
    while(1){
        int pos = -1;
        for(int i=1;i<=n;i++){
            if(a[i] % 2 == 0 && i != id){
                pos = i;
            }
        }
        if(pos == -1) break;
        a[pos] /= 2;
        a[id] *= 2;
    }
    ll sum = 0;
    for(int i=1;i<=n;i++) sum += a[i];
    cout << sum << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}