#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 92

using namespace std;

map <string, string> mp;

string str1, str2;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(i = 1; i <= n; i++) {
        cin >> str1 >> str2;
        mp[str2] = str1;
    }
    for(i = 1; i <= m; i++) {
        cin >> str1 >> str2;
        str2.pop_back();
        cout << str1 << " " << str2 << ";" << " " << "#" << mp[str2] << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}