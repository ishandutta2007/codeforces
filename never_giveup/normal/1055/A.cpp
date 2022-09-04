#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double ld;

void setmax(int &x, int y){
    x = max(x, y);
}

const int maxn = 1e5 + 100, inf = 1e9 + 100;

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
//	freopen("a.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (!a[0]){
        cout << "no";
        return 0;
    }
    s--;
    if (a[s]){
        cout << "yes";
        return 0;
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++){
        cin >> b[i];
        if (a[i] && b[i] && i > s && b[s]){
            cout << "yes";
            return 0;
        }
    }
    cout << "no";
}