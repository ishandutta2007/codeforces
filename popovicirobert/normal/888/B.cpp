#include <bits/stdc++.h>
#define ll long long
#define lsb(x) (x & (-x))


using namespace std;

string str;

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> str;
    int mn1 = 0, mn2 = 0;
    int cnt1 = 0, cnt2 = 0;
    for(i = 0; i < n; i++) {
        if(str[i] == 'U') {
            mn1++;
            cnt1++;
        }
        else if(str[i] == 'D')
            cnt1++;
        if(str[i] == 'L') {
            mn2++;
            cnt2++;
        }
        else if(str[i] == 'R')
            cnt2++;
    }
    mn1 = min(mn1, cnt1 - mn1);
    mn2 = min(mn2, cnt2 - mn2);
    cout << 2 * (mn1 + mn2);
    //cin.close();
    //cout.close();
    return 0;
}