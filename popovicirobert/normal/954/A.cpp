#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

string str;
char stk[101];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> str;
    int sz = 0;
    for(i = 0; i < n; i++) {
        if(sz > 0) {
            if(str[i] == 'R' && stk[sz] == 'U') {
                stk[sz] = 'D';
            }
            else if(str[i] == 'U' && stk[sz] == 'R') {
                stk[sz] = 'D';
            }
            else
                stk[++sz] = str[i];
        }
        else
            stk[++sz] = str[i];
    }
    cout << sz;
    //cin.close();
    //cout.close();
    return 0;
}