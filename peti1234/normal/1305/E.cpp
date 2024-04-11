#include <bits/stdc++.h>

using namespace std;
int n, m, sum, db, el, nagy=500000000;
int main()
{
    cin >> n >> m;
    sum=(n/2)*(n/2);
    if (n%2==0) sum-=n/2;
    if (m>sum) {
        cout << "-1" << endl;
        return 0;
    }
    for (int i=1; m>0; i++) {
        if ((el-i/2)<=m) {
            m-=el-i/2;
            el=i;
            cout << i << " ";
            db++;
        }
    }
    for (int i=nagy; db<n; i+=10001) {
        cout << i << " ";
        db++;
    }
    return 0;
}