#include <bits/stdc++.h>

using namespace std;
long long n, x, db, sum;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> x;
        if (x>0) {
            sum+=x-1;
        }
        if (x<0) {
            sum+=-x-1;
            db++;
        }
        if (x==0) {
            sum++;
            db=-1e9;
        }
    }
    if (db>0 && db%2) {
        sum+=2;
    }
    cout << sum << "\n";
    return 0;
}