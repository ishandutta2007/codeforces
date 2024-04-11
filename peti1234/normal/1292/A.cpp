#include <bits/stdc++.h>

using namespace std;
int n, q;
int db;
int v[4][100003];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for (int i=1; i<=q; i++) {
        int a, b;
        cin >> a >> b;
        int c=a+1;
        if (c==3) c=1;
        int sum=v[c][b]+v[c][b+1]+v[c][b-1];
        if (v[a][b]) db-=sum;
        else db+=sum;
        v[a][b]=!v[a][b];

        if (db) cout << "No" << "\n";
        else cout << "Yes" << "\n";

    }
    return 0;
}