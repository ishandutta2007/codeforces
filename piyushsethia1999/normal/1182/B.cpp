#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
    int n; cin >> n;
    int m; cin >> m;
    string s[n];
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    int star = 0;
    int ii = -1;
    int jj = -1;
    int mar = 0;
    for (int i = 1; i < n - 1; ++i) {
        for (int j = 1; j < m - 1; ++j) {
            if (s[i][j]=='*') {
                if (s[i-1][j] == '*' && s[i][j - 1] == '*' && s[i + 1][j] == '*' && s[i][j + 1] == '*') {
                    ii = i; jj = j;
                    i = ii; j = jj + 1;
                    while (j < m && s[i][j] == '*') {
                        s[i][j] = '.';
                        j++;
                    }
                    i = ii; j = jj - 1;
                    while (j >= 0 && s[i][j] == '*') {
                        s[i][j] = '.';
                        j--;
                    }
                    i = ii - 1; j = jj;
                    while (i >= 0 && s[i][j] == '*') {
                        s[i][j] = '.';
                        i--;
                    }
                    i = ii + 1; j = jj;
                    while (i < n && s[i][j] == '*') {
                        s[i][j] = '.';
                        i++;
                    }
                    star++;
                    i = ii; j = jj;
                    s[i][j] = '.';
                }
            } 
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == '*') {
                star = 0;
            } 
        }
    }
    if (star == 1) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}