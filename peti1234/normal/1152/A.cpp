#include <bits/stdc++.h>

using namespace std;
int n, m;
int oa, ea, ob, eb;
int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        int a;
        cin >> a;
        if (a%2==0) {
            ea++;
        } else {
            oa++;
        }
    }
    for (int i=1; i<=m; i++) {
        int a;
        cin >> a;
        if (a%2==0) {
            eb++;
        } else {
            ob++;
        }
    }
    int x=0;
    x+=min(ea, ob);
    x+=min(oa, eb);
    cout << x << endl;
    return 0;
}