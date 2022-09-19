#include <bits/stdc++.h>

using namespace std;
int n, p=1, db;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    if (n<=2) {
        cout << 0 << endl;
        return 0;
    }
    while(2*p<=n) p*=2, db++;
    cout << p*db << "\n";
    for (int i=0; i<db; i++) {
        for (int j=0; j<p; j++) {
            if ((j&(1<<i))==0) cout << j+1 << " " << j+(1<<i)+1 << endl;
        }
    }
    for (int i=0; i<db; i++) {
        for (int j=0; j<p; j++) {
            if ((j&(1<<i))==0) cout << n-j << " " << n-j-(1<<i) << endl;
        }
    }
    return 0;
}
// f