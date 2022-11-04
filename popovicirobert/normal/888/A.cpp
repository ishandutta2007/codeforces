#include <bits/stdc++.h>
#define ll long long
#define lsb(x) (x & (-x))


using namespace std;

int v[10001];

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> v[i];
    }
    int ans = 0;
    for(i = 2; i < n; i++) {
        if(v[i] > v[i - 1] && v[i] > v[i + 1])
            ans++;
        else if(v[i] < v[i - 1] && v[i] < v[i + 1])
            ans++;
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}