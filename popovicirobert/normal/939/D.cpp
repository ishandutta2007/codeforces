#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 217
// 44

using namespace std;

string str1, str2;

vector <int> g[26];

int sef[26];

int myfind(int x) {
    if(sef[x] == -1)
        return x;
    return sef[x] = myfind(sef[x]);
}

int cnt = 0;

inline void myunion(int x, int y) {
    if(myfind(x) != myfind(y)) {
        sef[myfind(x)] = myfind(y);
        g[x].push_back(y);
        cnt++;
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> str1 >> str2;
    memset(sef, -1, sizeof(sef));
    for(i = 0; i < n; i++) {
        str1[i] -= 'a';
        str2[i] -= 'a';
        myunion(str1[i], str2[i]);
    }
    cout << cnt << "\n";
    for(i = 0; i < 26; i++) {
        for(auto it : g[i]) {
            cout << (char) (i + 'a') << " " << (char) (it + 'a') << "\n";
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}