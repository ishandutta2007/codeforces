#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;




int main() {
#ifdef HOME
    ifstream cin("C.in");
    ofstream cout("C.out");
#endif
    int i, t;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    map<int, bool> mp;
    vector<int> s;

    int a = 1;
    for(i = 1; i <= 300; i++) {
        while(mp[a]) {
            a++;
        }
        mp[a] = 1;
        int b = a + 1;
        while(true) {
            if(mp[b] == 0 && mp[a ^ b] == 0) {
                mp[b] = mp[a ^ b] = 1;
                s.push_back(a);
                s.push_back(b);
                s.push_back(a ^ b);
                break;
            }
            b++;
        }
    }

    cin >> t;
    while(t--) {
        ll n; cin >> n;
        if(n <= 3) {
            cout << s[n - 1] << "\n";
            continue;
        }
        int bit = 2;
        while((1LL << bit) <= n) {
            bit += 2;
        }
        ll a, b = 0;
        a = (1LL << (bit - 2)) + (n - (1LL << (bit - 2))) / 3;

        function <ll(int, ll)> solve = [&](int bit, ll n) {

            if(bit == 0) {
                return 0LL;
            }
            
            if(n <= (1LL << (bit - 2))) {
                return solve(bit - 2, n);
            }
            if(n <= (1LL << (bit - 1))) {
                return solve(bit - 2, n - (1LL << (bit - 2))) ^ (1LL << (bit - 1));
            }
            if(n <= (3LL << (bit - 2))) {
                return solve(bit - 2, n - (1LL << (bit - 1))) ^ (1LL << (bit - 1)) ^ (1LL << (bit - 2));
            }
            return solve(bit - 2, n - (3LL << (bit - 2))) ^ (1LL << (bit - 2));
        };

        b = solve(bit - 2, (n - (1LL << (bit - 2))) / 3 + 1) + (1LL << (bit - 1));

        if(n % 3 == 1) {
            cout << a << "\n";
        }
        if(n % 3 == 2) {
            cout << b << "\n";
        }
        if(n % 3 == 0) {
            cout << (a ^ b) << "\n";
        }
    }

    // 8

    return 0;
}