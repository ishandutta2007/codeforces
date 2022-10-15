#include <iostream>

using namespace std;

typedef long long ll;

int g[5050];
int s[5050];
ll d[5050];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> g[i];
        for (int i = 1; i <= n; i++) cin >> s[i];
        for (int i = 1; i <= n; i++) d[i] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i-1; j >= 1; j--) {
                if (g[j] == g[i]) continue;
                ll u = d[i]+abs(s[j]-s[i]);
                d[i] = max(d[i],d[j]+abs(s[j]-s[i]));
                d[j] = max(d[j],u);
            }
        }
        ll r = 0;
        for (int i = 1; i <= n; i++) {
            r = max(r,d[i]);
        }
        cout << r << "\n";
    }
}