#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        int lr=0, ud=0, fixn=(n==1 ? 1 : 0), fixm=(m==1 ? 1 : 0);
        int bal=0, jobb=0, le=0, fel=0;
        for (auto c:s) {
            if (c=='L') lr--, bal=min(bal, lr);
            if (c=='R') lr++, jobb=max(jobb, lr);
            if (c=='U') ud--, fel=min(fel, ud);
            if (c=='D') ud++, le=max(le, ud);
            if (!fixm && jobb-bal==m-1) fixm=1-bal;
            if (!fixn && le-fel==n-1) fixn=1-fel;
        }
        if (!fixm) fixm=1-bal;
        if (!fixn) fixn=1-fel;

        cout << fixn << " " << fixm << "\n";
    }
    return 0;
}