#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        string a, b;
        cin >> a >> b;
        bool baj=0;
        set<char> s;
        int n=a.size(), m=b.size(), pos=m-1;
        for (int i=n-1; i>=0; i--) {
            if (pos>=0 && a[i]==b[pos]) {
                if (s.find(b[pos])!=s.end()) {
                    baj=1;
                }
                pos--;
            } else {
                s.insert(a[i]);
            }
        }
        cout << (pos==-1 && !baj ? "YES" : "NO") << "\n";
    }
    return 0;
}