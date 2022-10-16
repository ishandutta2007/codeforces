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



void solve(){
    int n; cin >> n;
    if(n == 1){
        cout << 1 << "\n";
        cout << 1 << " " << 1 << "\n";
        return;
    }
    for(int a=1;a<=n;a++){
        int diags = (n - a) * 2 - 1;
        if(a >= diags){
            cout << a << "\n";

            int fiDiags = diags / 2 + 1;
            int seDiags = diags - fiDiags;

            for(int i=fiDiags;i>=1;i--){
                cout << n - a + i << " " << n - a + (fiDiags - i + 1) << "\n";
            }

            for(int i=1;i<=seDiags;i++){
                cout << n - i + 1 << " " << n - (seDiags - i) << "\n";
            }

            int want = a - diags;
            for(int i=1;i<=want;i++){
                cout << n - seDiags - i + 1 << " " << n - seDiags - i + 1 << "\n";
            }

            return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}