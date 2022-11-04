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
    int cnt0 = 0, cnt1 = 0;
    for(i = 0; i < n; i++) {
        if(str[i] == '0')
            cnt0++;
        else
            cnt1++;
    }
    while(cnt1 > 1) {
        cnt1--;
    }
    if(cnt1 > 0)
        cout << 1;
    while(cnt0 > 0) {
        cnt0--;
        cout << 0;
    }
    //cin.close();
    //cout.close();
    return 0;
}