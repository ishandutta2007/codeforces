#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n, mini=30, cnt=0;
        cin >> n;
        while (n--) {
            int x, db=0;
            cin >> x;
            while (x%2==0) {
                x/=2;
                db++;
            }
            //cout << "fontos " << db << "\n";
            if (db) cnt++;
            mini=min(mini, db);
        }
        cout << mini+cnt-(mini>0) << "\n";
    }
    return 0;
}
/*
1
3
1049600 33792 1280
*/