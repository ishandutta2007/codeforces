#include <bits/stdc++.h>

using namespace std;
int n;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> s;
    for (int i=1; i<=n; i++) {
        if (n%i==0) {
            reverse(s.begin(), s.begin()+i);
        }
    }
    cout << s << "\n";
    return 0;
}