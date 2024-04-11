#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

map <int, int> mp;

int main() {
    //ifstream cin("strava.in");
    //ofstream cout("strava.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    ll ans = 0;
    while(n > 0) {
        n--;
        string str;
        cin >> str;
        int cnf = 0;
        for(auto it : str) {
            cnf ^= (1 << (it - 'a'));
        }
        ans += mp[cnf];
        for(i = 0; i < 26; i++) {
            ans += mp[cnf ^ (1 << i)];
        }
        mp[cnf]++;
    }
    cout << ans << "\n";
    //cin.close();
    //cout.close();
    return 0;
}