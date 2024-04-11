#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int) 3e5;

vector <int> g[MAXN + 1];
int arr[MAXN + 1], fr[MAXN + 1], deg[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for(i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[b].push_back(a);
        deg[a]++;
    }
    int lazy = 0;
    int ans = 0;
    for(i = n; i >= 1; i--) {
        if(i < n && (n - i) == lazy + fr[arr[i]]) {
            ans++, lazy++;
        }
        else {
            for(auto it : g[arr[i]]) {
                fr[it]++;
            }
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}