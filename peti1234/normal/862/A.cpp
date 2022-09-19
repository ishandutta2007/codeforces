#include <bits/stdc++.h>

using namespace std;
int n, x;
bool p[101];
int k;
int main()
{
    cin >> n >> x;
    for (int i=1; i<=n; i++) {
        int y;
        cin >> y;
        p[y]=true;
        //cout << y << " " << p[y] << endl;
        if (y==x) {
            k++;
        }
    }
    for (int i=0; i<x; i++) {
        if (!p[i]) {
            k++;
        }
    }
    cout << k << endl;
    return 0;
}