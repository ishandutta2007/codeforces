#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;

string str;

int fr[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> str;
    int ans = 0;
    for(i = 0; i < n; i++) {
        memset(fr, 0, sizeof(fr));
        if('a' <= str[i] && str[i] <= 'z') {
            int j = i;
            int cnt = 0;
            while(j < n && ('a' <= str[j] && str[j] <= 'z')) {
                if(fr[str[j] - 'a'] == 0)
                   cnt++;
                fr[str[j] - 'a']++;
                j++;
            }
            ans = max(ans, cnt);
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}