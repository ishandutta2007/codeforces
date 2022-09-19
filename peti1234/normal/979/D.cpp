#include <bits/stdc++.h>

using namespace std;
const int c=100002;
int n, t[300*c][3], cnt=c-1;
vector<int> oszt[c];
int main()
{
    ios_base::sync_with_stdio(false);
    for (int i=1; i<c; i++) for (int j=i; j<c; j+=i) oszt[j].push_back(i);
    for (int i=0; i<300*c; i++) t[i][2]=c;
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x, a, b, c;
        cin >> x >> a;
        if (x==1) for (int i=0; i<oszt[a].size(); i++) {
            int pos=oszt[a][i]; t[pos][2]=min(t[pos][2], a);
            for (int i=17; i>=0; i--) {
                bool v=a&(1<<i);
                if (!t[pos][v]) t[pos][v]=cnt, cnt++;
                pos=t[pos][v], t[pos][2]=min(t[pos][2], a);
            }
        } else {
            cin >> b >> c;
            int pos=b; c-=a;
            for (int i=17; i>=0; i--) {
                bool v=!(a&(1<<i));
                int x=t[pos][v], y=t[pos][!v];
                if (t[x][2]<=c) pos=x;
                else pos=y;
            }
            int x=t[pos][2];
            if (x>c || a%b || x%b) cout << -1 << "\n";
            else cout << x << "\n";
        }
    }
    return 0;
}