#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

string str;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> str;
    str = " " + str;
    int ans = n;
    for(int len = 1; len <= n; len++) {
        if(2 * len <= n) {
            i = len + 1;
            while(i <= 2 * len && str[i] == str[i - len])
                i++;
            if(i == 2 * len + 1)
                ans = min(ans, len + 1 + n - 2 * len);
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}