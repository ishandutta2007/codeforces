#include <bits/stdc++.h>
#define ll long long



using namespace std;


int v[1000];



int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(i = 1; i <= n; i++)
        cin >> v[i];
    sort(v + 1, v + n + 1, greater <int>());
    int ans = 0;
    for(i = 1; i <= n && m > 0; i++) {
         m -= v[i];
         ans++;
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}