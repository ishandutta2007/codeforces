#include <bits/stdc++.h>
#define ll long long
#define MAXN 200000

using namespace std;


pair <int, int> a[MAXN + 1], b[MAXN + 1];
int sol[MAXN + 1];

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    for(i = 1; i <= m; i++) {
        cin >> b[i].first;
        b[i].second = i;
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    int p = 1;
    for(i = 1; i <= m; i++) {
        while(p <= n && a[p].first <= b[i].first)
            p++;
        sol[b[i].second] = p - 1;
    }
    for(i = 1; i <= m; i++)
        cout << sol[i] << " ";
    //cin.close();
    //cout.close();
    return 0;
}