#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

string str;
int fr[10];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n;
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> str;
    for(auto it : str) {
        fr[it - '0']++;
    }
    int ans = 0;
    for(int i = 1; i <= fr[8]; i++) {
        if(i <= (n - i) / 10) {
            ans = i;
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}