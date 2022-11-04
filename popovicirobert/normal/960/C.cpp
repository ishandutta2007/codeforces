#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

vector <ll> sol;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int x, d;
    ios::sync_with_stdio(false);
    cin >> x >> d;
    ll val = 1;
    int cnt = 0;
    for(int bit = 30; bit >= 0; bit--) {
        if(x & (1 << bit)) {
            cnt++;
            for(int i = 0; i < bit; i++) {
                sol.push_back(val);
            }
            val += d + 1;
        }
    }
    while(cnt > 0) {
        cnt--;
        sol.push_back(val);
        val += d + 1;
    }
    cout << sol.size() << "\n";
    for(auto it : sol) {
        cout << it << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}