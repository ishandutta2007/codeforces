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
    int ans = 0, cnt = 0;
    for(auto it : str) {
        if(it == 'x') {
            cnt++;
        }
        else {
            ans += max(0, cnt - 2);
            cnt = 0;
        }
    }
    ans += max(0, cnt - 2);
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}