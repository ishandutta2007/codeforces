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
ll a[nax];
int n;

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    ll sum = 0;
    for(int i=1;i<=n;i++){
        sum += a[i];
    }
    priority_queue<ll> Q;
    int w = n;
    Q.push(sum);
    for(int i=1;i<n;i++){
        ll cur = Q.top();
        if(cur == a[w]){
            Q.pop();
            w--;
            i--;
            continue;
        }
        Q.pop();
        Q.push(cur / 2);
        Q.push((cur + 1) / 2);
    }
    while(Q.size() && Q.top() == a[w]){
        w--;
        Q.pop();
    }
    if(w == 0) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}