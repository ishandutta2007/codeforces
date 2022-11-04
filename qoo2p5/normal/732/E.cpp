#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld EPS = 1e-7;

const int N = 2e5 + 123;

int n, m;
pair<int, int> p[N], s[N];
int a[N], b[N];
bool used[N];

int run() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> p[i].first;
        p[i].second = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> s[i].first;
        s[i].second = i;
    }
    
    sort(p, p + n);
    sort(s, s + m);
    
    int c = 0;
    int u = 0;
    
    for (int step = 0; step < 32; step++) {
        int j = 0;
        
        for (int i = 0; i < m; i++) {
            if (used[i]) {
                continue;
            }
            
            while (j + 1 < n && (p[j].first < s[i].first || b[p[j].second] != 0)) {
                j++;
            }
            
            if (p[j].first == s[i].first && b[p[j].second] == 0) {
                b[p[j].second] = s[i].second + 1;
                a[s[i].second] = step;
                used[i] = true;
                c++;
                u += step;
            }
            
            s[i].first = s[i].first / 2 + s[i].first % 2;
        }
    }
    
    cout << c << " " << u << "\n";
    for (int i = 0; i < m; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << "\n";
    
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    return run();
}