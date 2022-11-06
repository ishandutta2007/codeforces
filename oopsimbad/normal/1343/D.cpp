#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair<int,int> pii;
typedef long long ll;
 
#define forn(i, n) for (int i = 0; i < (n); i++)
#define mp make_pair
#define pb push_back
 
const int MAXN = 4e5 + 10;
const int MOD = 1e9 + 7;
 
int t, n, k;
int arr[MAXN], x[MAXN];
vector<pii> sd;
vector<int> fuck_u;
int updatePrefixArray() {
    forn(i, 2 * k + 1) x[i] = 0;
    forn(i, sd.size()) {
        int s = sd[i].first;
        int d = sd[i].second;
        x[s]++; x[d + 1]--;
    }
    forn(i, fuck_u.size()) {
        int bruh = fuck_u[i];
        x[bruh]++; x[bruh+1]--;
    }
    for (int i = 2; i <= 2 * k; i++) {
        x[i] += x[i - 1];
    }
    int best = -1, loc = -1;
    for (int i = 2; i <= 2 * k; i++) {
        if (x[i] > best) {
            best = x[i];
            loc = i;
        }
    }
    return best;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    cin >> t;
 
    while (t--) {
        cin >> n >> k;
        forn(i, n) cin >> arr[i];
        sd.clear();
        fuck_u.clear();
        forn(i, n / 2) {
            int j = n - i - 1;
            sd.pb(mp(min(arr[i],arr[j])+1, k+max(arr[i],arr[j])));
            fuck_u.pb(arr[i]+arr[j]);
        }
        int optX = updatePrefixArray();
        cout << n-optX << endl;
    }
 
    return 0;
}