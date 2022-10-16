#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef long long ll;
const int M = 2e5 + 5, MOD = 1e9+7;
map<int, int> s, ind;
int v[M], par[M];

vector<int> ans;
void rec(int n) {
    if (par[n]) rec(par[n]);
    ans.push_back(n);
    cout << n << ' ';
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    srand(time(0));
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    for (int i = 1; i <= n; i++) if (!ind[v[i]]) ind[v[i]] = i;

    for (int i = 1; i <= n; i++) {
        s[v[i]] = 1ll;
        ind[v[i]] = i;
        if (s[v[i]] < s[v[i]-1]+1) {
            par[i] = ind[v[i]-1];
            s[v[i]] = s[v[i]-1]+1;
        }
    }

    int a, b;
    a = b = INT_MIN;
    for (int i = 1; i <= n; i++) {
        if (s[v[i]] >= a) {
            a = s[v[i]];
            b = i;
        }
    }

    cout << a << endl;
    rec(b); cout << endl;

    return 0;
}