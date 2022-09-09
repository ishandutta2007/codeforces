#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
const int MAXN = 2005;

int n;
int ans[MAXN];
vector <pii > v;

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        v.puba(mapa(-num, i));
    }

    sort(bend(v));


    for (int i = 1; i < szof(v); ++i) {
        if (v[i].ff != v[i - 1].ff) {
            ans[v[i].ss] = i;
        } else {
            ans[v[i].ss] = ans[v[i - 1].ss];
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] + 1 << " ";
    }
    cout << endl;

    return 0;
}