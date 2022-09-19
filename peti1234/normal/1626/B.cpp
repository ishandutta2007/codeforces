#include <bits/stdc++.h>

using namespace std;
void solve(string s) {
    int n=s.size();
    for (int i=n-1; i>=1; i--) {
        int p=s[i]-'0'+s[i-1]-'0';
        if (p>=10 || i==1) {
            for (int j=0; j<=i-2; j++) cout << s[j];
            cout << p;
            for (int j=i+1; j<n; j++) cout << s[j];
            cout << "\n";
            return;
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        string s;
        cin >> s;
        solve(s);
    }
    return 0;
}