#include <bits/stdc++.h>

using namespace std;
const int c=100002;
int w, db[c], n, m, sum;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        sum=0;
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            int x; cin >> x;
            db[x%m]++;
        }
        if (db[0]) {
            sum++;
        }
        if (m%2==0 && db[m/2]) {
            sum++;
        }
        for (int i=1; i<=(m-1)/2; i++) {
            int a=db[i], b=db[m-i];
            if (a || b) {
                sum+=max(1, abs(a-b));
            }
        }
        cout << sum << "\n";
        for (int i=0; i<m; i++) {
            db[i]=0;
        }
    }
    return 0;
}
/*
1
6 4
2 2 8 6 9 4
*/