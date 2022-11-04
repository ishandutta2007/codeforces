#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 217
// 44

using namespace std;

string str;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, ans = 0;
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> str;
    int ok = 0, x = 0, y = 0;
    for(auto it : str) {
        if(it == 'R')
            x++;
        else
            y++;
        if(x > y && ok == 1)
            ans++;
        if(x > y)
            ok = -1;
        if(x < y && ok == -1)
            ans++;
        if(x < y)
            ok = 1;
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}