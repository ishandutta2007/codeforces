#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    char mini='9';
    int n=s.size();
    for (int i=n-1; i>=0; i--) {
        if (s[i]<=mini) mini=s[i];
        else if (s[i]!='9') s[i]++;
    }
    sort(s.begin(), s.end());
    cout << s << "\n";

}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}