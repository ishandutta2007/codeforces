#include <bits/stdc++.h>

using namespace std;
int cnt=0;
map<string, int> m;
int main()
{
    ios_base::sync_with_stdio(false);
    for (char x='a'; x<='z'; x++) {
        for (char y='a'; y<='z'; y++) {
            if (x!=y) {
                string s;
                s.push_back(x), s.push_back(y);
                m[s]=++cnt;
            }
        }
    }
    int w;
    cin >> w;
    while (w--) {
        string s;
        cin >> s;
        cout << m[s] << "\n";
    }
    return 0;
}