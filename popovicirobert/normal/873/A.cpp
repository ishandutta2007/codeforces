#include <bits/stdc++.h>
#define ll long long

using namespace std;

int v[1000];

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, k, x;
    ios::sync_with_stdio(false);
    cin >> n >> k >> x;
    for(i = 1; i <= n; i++)
        cin >> v[i];
    sort(v + 1, v + n + 1);
    int ans = 0;
    for(i = n; i >= 1; i--) {
        if(k > 0) {
            if(v[i] > x) {
                ans += x;
                k--;
            }
            else
                ans += v[i];
        }
        else
            ans += v[i];
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}