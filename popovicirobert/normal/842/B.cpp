#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    float R, D;
    int n;
    ios::sync_with_stdio(false);
    cin >> R >> D;
    cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        float x, y, r;
        cin >> x >> y >> r;
        if(sqrt(x * x + y * y) - r - R + D >= 0 && R - sqrt(x * x + y * y) - r >= 0)
            ans++;
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}