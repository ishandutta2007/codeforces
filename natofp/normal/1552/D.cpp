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

int a[15];

void solve(){
    int n; cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
        //a[i] = abs(a[i]);
    }
    bool ok = false;
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<(1<<n);j++){
            int s1 = 0;
            int s2 = 0;
            for(int k=0;k<n;k++){
                if(i & (1 << k)) s1 += a[k];
                if(j & (1 << k)) s2 += a[k];
            }
            if(i != j && s1 == s2){
                ok = true;
            }
        }
    }
    if(ok) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
cin >> tt;
    while(tt--) solve();

    return 0;
}