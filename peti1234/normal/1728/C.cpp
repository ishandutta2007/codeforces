#include <bits/stdc++.h>

using namespace std;
priority_queue<int> p[2];
int len(int x) {
    int s=0;
    while (x) {
        s++, x/=10;
    }
    return s;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n, ans=0;
        cin >> n;
        for (int j=0; j<2; j++) {
            for (int i=1; i<=n; i++) {
                int x;
                cin >> x;
                p[j].push(x);
            }
        }
        while (p[0].size()>0) {
            int a=p[0].top(), b=p[1].top();
            if (a==b) {
                p[0].pop(), p[1].pop();
            }
            if (a>b) {
                ans++;
                p[0].pop();
                p[0].push(len(a));
            }
            if (b>a) {
                ans++;
                p[1].pop();
                p[1].push(len(b));
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
/*
1
1
1
1000
*/