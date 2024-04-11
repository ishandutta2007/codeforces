#include <bits/stdc++.h>

using namespace std;
char p[32];
int n, ans[200002], cnt=1;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    for (int i=1; i<30; i++) {
        p[i]='a';
    }
    cin >> n >> s;
    for (int i=0; i<n; i++) {
        int pos=1;
        while (p[pos]>s[i]) {
            pos++;
        }
        cnt=max(cnt, pos);
        ans[i+1]=pos;
        p[pos]=s[i];
    }
    cout << cnt << "\n";
    for (int i=1; i<=n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}