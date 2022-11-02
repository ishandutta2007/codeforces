#include <iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<vector<bool>> vvb;
typedef vector<bool> vb;
typedef vector<int> vi;
int main() {
   //freopen("transform.in", "r", stdin);
    //freopen("transform.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    for(int i = 0;i < q;i++) {
        int l,r,d;
        cin >> l >> r >> d;
        if (d < l || d > r) cout << d << '\n';
        else cout << (r / d + 1) * d << '\n';
    }
}