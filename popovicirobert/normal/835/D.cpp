#include <bits/stdc++.h>
#define ll long long


using namespace std;

const int MAXN = (int) 5000;

string str;

int l[2 * MAXN + 10];
char v[2 * MAXN + 10];

short dp[2 * MAXN + 10][2 * MAXN + 10];
int ans[MAXN + 1];

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n, p;
    cin >> str;
    n = str.size();
    p = 0;
    for(i = 1; i <= n; i++) {
        p++;
        v[p] = '*';
        p++;
        v[p] = str[i - 1];
    }
    p++;
    v[p] = '*';
    int sz = p;
    for(i = 1; i <= sz; i++) {
        int p1 = i, p2 = i;
        while(p1 > 0 && p2 <= sz && v[p1] == v[p2]) {
            p1--;
            p2++;
        }
        l[i] = p2 - i;
    }
    for(i = 1; i <= sz; i++) {
        dp[i][i] = 1;
        if(v[i] != '*') {
           ans[1]++;
           ans[2]--;
        }
    }
    for(int len = 2; len <= sz; len += 2)
       for(i = 1; i + len <= sz; i++) {
            j = i + len;
            int med = (i + j) / 2;
            if(l[med] > len / 2)
                dp[i][j] = std::min(dp[i][med - 1 - (v[med - 1] == '*')], dp[med + 1 + (v[med + 1] == '*')][j]) + 1;
            else
                dp[i][j] = 0;
            if(v[i] != '*') {
              ans[1]++;
              ans[dp[i][j] + 1]--;
            }
       }
    for(i = 1; i <= n; i++) {
        ans[i] += ans[i - 1];
        cout << ans[i] << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}