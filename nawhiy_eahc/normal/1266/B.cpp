#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll x; cin >> x;
        if(x >= 14 && 1 <= x%14 && x%14 <= 6) cout << "YES\n";
        else cout << "NO\n";
    }
}