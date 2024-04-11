#include <bits/stdc++.h>

using namespace std;
int w, n;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> s;
        n=s.size();
        set<char> c;
        int pos=n-1;
        for (int i=n-1; i>=0; i--) {
            if (c.find(s[i])==c.end()) {
                pos=i;
                c.insert(s[i]);
            }
        }
        cout << s.substr(pos, n-pos) << "\n";
    }
    return 0;
}