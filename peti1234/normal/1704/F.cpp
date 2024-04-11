#include <bits/stdc++.h>

using namespace std;
const int c=500005;
int w, n, cnt, len, ert, gr[c];
int main()
{
    for (int i=2; i<100; i++) {
        set<int> s;
        for (int j=0; j<=i-2; j++) {
            s.insert(gr[j]^gr[i-j-2]);
        }
        while (s.count(gr[i])) {
            gr[i]++;
        }
    }
    for (int i=100; i<c; i++) {
        gr[i]=gr[i-34];
    }

    cin >> w;
    while (w--) {
        cin >> n;
        string s;
        cin >> s;
        for (int i=0; i<n; i++) {
            if (s[i]=='R') cnt++;
            else cnt--;
            if (i==0 || s[i]!=s[i-1]) len++;
            else {
                ert^=gr[len];
                len=1;
            }
        }
        ert^=gr[len];
        cout << (cnt>0 || cnt==0 && ert ? "Alice" : "Bob") << "\n";

        cnt=0, len=0, ert=0;
    }
    return 0;
}