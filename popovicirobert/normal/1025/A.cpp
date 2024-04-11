#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

string str;
int fr[26];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, i;
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> str;
    if(n == 1) {
        cout << "Yes";
        return 0;
    }
    for(auto it : str) {
        fr[it - 'a']++;
    }
    int mx = 0;
    for(i = 0; i < 26; i++) {
        mx = max(mx, fr[i]);
    }
    if(mx > 1)
        cout << "Yes";
    else
        cout << "No";
    //cin.close();
    //cout.close();
    return 0;
}