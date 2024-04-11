#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int) 2e5;

char str[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, k;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> k >> str + 1;
    n = strlen(str + 1);
    int ans = 0;
    for(int ch = 'a'; ch <= 'z'; ch++) {
        int cur = 0;
        i = 1;
        while(i <= n) {
            int j = i;
            while(j <= n && str[i] == str[j]) {
                j++;
            }
            if(str[i] == ch) {
                cur += (j - i) / k;
            }
            i = j;
        }
        ans = max(ans, cur);
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}