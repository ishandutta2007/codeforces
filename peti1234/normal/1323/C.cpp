#include <bits/stdc++.h>

using namespace std;
int n, db, cnt;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> s;
    for (int i=0; i<n; i++) {
        if (s[i]=='(') cnt++;
        else cnt--;
        if (cnt<0 || (cnt==0 && s[i]=='(')) db++;
    }
    if (cnt!=0) cout << -1 << "\n";
    else cout << db << "\n";
    return 0;
}