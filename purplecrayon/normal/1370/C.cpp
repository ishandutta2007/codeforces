#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
const int MAXN = 2e6+10, ALP = 26, MAXL = 20, INF = 1e9+10, MOD = 1e9+7;

const string p1 = "Ashishgup\n", p2 = "FastestFinger\n";

void solve(){
    int n; cin >> n;
    if (n==1){ cout << p2; return; }
    if ((n&1) || n==2){ cout << p1; return; }
    int nn = n, nm = 0;
    while (nn%2 == 0) nn /= 2, nm++;
    if (nn == 1){ cout << p2; return; }
    int w = 0;
    for (int i = 3; i*i <= nn; i++) if (nn%i == 0) w = 1;
    if (nm > 1 || (nm == 1 && w)){ cout << p1; return; }
    cout << p2; return; 
}
int main(){
    int t=1; cin >> t;
    while (t--) solve();
}