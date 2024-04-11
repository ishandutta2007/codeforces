#include <bits/stdc++.h>

using namespace std;
int w, n;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> s;
        sort(s.begin(), s.end());
        cout << s << "\n";

    }
    return 0;
}