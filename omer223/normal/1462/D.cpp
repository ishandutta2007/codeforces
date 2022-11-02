#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve() {
    int n;
    ll sm = 0;
    cin >> n;
    vector<int> a(n);
    foru(i, 0, n) {
        cin >> a[i];
        sm += a[i];
    }
    int bst = 1;
    for (int div = 1; div <= n; div++) {
        if (sm % div != 0) continue;
        ll need = sm/div, cur=0;
        bool bad=0;
        foru(i,0,n){
            cur+=a[i];
            if(cur>need){
                bad=1;
                break;
            }
            else if (cur==need)cur=0;
        }
        if(!bad)bst=div;
    }
    cout << n - bst << '\n';
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}