#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w;
    cin >> w;
    while (w--) {
        int n, m;
        cin >> n >> m;
        string s(m, 'B');
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            int a=x-1, b=m-x;
            if (a>b) swap(a, b);
            if (s[a]=='A') s[b]='A';
            else s[a]='A';
        }
        cout << s << endl;
    }
    return 0;
}