#include <bits/stdc++.h>
#define ll long long


using namespace std;

const int MAXN = (int) 1e6;

pair <int, int> a[MAXN + 1], b[MAXN + 1];
int sol[MAXN + 1];

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    for(i = 1; i <= n; i++) {
        cin >> b[i].first;
        b[i].second = i;
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    for(i = n; i >= 1; i--)
        sol[b[n - i + 1].second] = a[i].first;
    for(i = 1; i <= n; i++)
        cout << sol[i] << " ";
    //cin.close();
    //cout.close();
    return 0;
}