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
int a[nax];
int cnt[10];

void solve(){
    int n; cin >> n;
    for(int i=0;i<10;i++) cnt[i] = 0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(a[i] < 10) cnt[a[i]] += 1;
    }

    if(cnt[1] == 0){
        cout << "YES" << "\n";
        return;
    }

    sort(a + 1, a + n + 1);
    bool ac = true;
    for(int i=2;i<=n;i++){
        if(a[i] == a[i - 1] + 1) ac = false;
    }
    if(ac) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}