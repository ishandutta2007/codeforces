#include <bits/stdc++.h>
#define ll long long
#define lsb(x) (x & (-x))


using namespace std;

const int MAXN = (int) 1e5;

int sp[MAXN + 1][26];

string str;
int n;

int fr[26];

inline bool check(int len) {
    int i, j;
    memset(fr, 0, sizeof(fr));
    for(i = len; i <= n; i++) {
        for(j = 0; j < 26; j++)
            if(sp[i][j] - sp[i - len][j] > 0)
                fr[j]++;
    }
    for(i = 0; i < 26; i++)
        if(n - len + 1 == fr[i])
            return 1;
    return 0;
}

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, j;
    ios::sync_with_stdio(false);
    cin >> str;
    n = str.size();
    str = " " + str;
    for(i = 1; i <= n; i++) {
        for(j = 0; j < 26; j++)
            sp[i][j] += sp[i - 1][j];
        sp[i][str[i] - 'a']++;
    }
    int rez = 0;
    for(int pas = 1 << 16; pas; pas >>= 1) {
        if(rez + pas <= n && check(rez + pas) == 0)
            rez += pas;
    }
    cout << rez + 1;
    //cin.close();
    //cout.close();
    return 0;
}