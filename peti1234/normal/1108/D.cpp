#include <bits/stdc++.h>

using namespace std;
int n, db;
string s;
void pr(int i, char c) {
    if (s[i-1]!=c && (i+1==n || s[i+1]!=c)) s[i]=c;
}
int main()
{
    cin >> n >> s;
    for (int i=1; i<n; i++) {
        if (s[i]==s[i-1]) {
            db++;
            pr(i, 'R'), pr(i, 'G'), pr(i, 'B');
        }
    }
    cout << db << "\n" << s << "\n";
    return 0;
}