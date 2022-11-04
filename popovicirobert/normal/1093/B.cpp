#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

string str;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    while(n > 0) {
        n--;
        cin >> str;
        sort(str.begin(), str.end());
        if(str[0] != str.back()) {
            cout << str;
        }
        else {
            cout << -1;
        }
        cout << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}