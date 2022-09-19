#include <bits/stdc++.h>

using namespace std;
const int c=100005;
int w, n, p[c], t[c], cnt;
bool v[c];
long long sum;
void dfs(int a) {
    v[a]=true;
    cnt++;
    if (!v[t[a]]) {
        dfs(t[a]);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> p[i];
        }
        for (int i=1; i<=n; i++) {
            cin >> t[p[i]];
        }
        for (int i=1; i<=n; i++) {
            if (!v[i]) {
                dfs(i);
                sum+=cnt/2;
                cnt=0;
            }
        }
        cout << sum*(n-sum)*2 << "\n";
        sum=0;
        for (int i=1; i<=n; i++) {
            v[i]=0;
        }
    }
    return 0;
}