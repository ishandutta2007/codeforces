#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

string str;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    //int ;
    ios::sync_with_stdio(false);
    cin >> str;
    int n = str.size();
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int l = i, r = j;
            while(l < r && str[l] == str[r]) {
                l++;
                r--;
            }
            if(l < r) {
                ans = max(ans, j - i + 1);
            }
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}