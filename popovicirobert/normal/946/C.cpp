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
    int i;
    ios::sync_with_stdio(false);
    cin >> str;
    int n = str.size();
    char cur = 0;
    for(i = 0; i < n; i++) {
        str[i] -= 'a';
        if(cur < 26 && str[i] <= cur) {
            str[i] = cur;
            cur++;
        }
    }
    if(cur < 26) {
        cout << -1;
        return 0;
    }
    for(i = 0; i < n; i++) {
        cout << (char) (str[i] + 'a');
    }
    //cin.close();
    //cout.close();
    return 0;
}