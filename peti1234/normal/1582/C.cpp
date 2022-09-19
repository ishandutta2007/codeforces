#include <bits/stdc++.h>

using namespace std;
int w, n, ans;
string s;
int solve(char c) {
    int bal=0, jobb=n-1, cnt=0;
    while (bal<jobb) {
        if (s[bal]!=s[jobb]) {
            cnt++;
            if (s[bal]==c) {
                bal++;
            } else if (s[jobb]==c) {
                jobb--;
            } else {
                return n+1;
            }
        } else {
            bal++, jobb--;
        }
    }
    return cnt;
}
int main()
{
    cin >> w;
    while (w--) {
        cin >> n >> s;
        ans=n+1;
        for (auto i='a'; i<='z'; i++) {
            ans=min(ans, solve(i));
        }
        cout << (ans==n+1 ? -1 : ans) << "\n";
    }
    return 0;
}