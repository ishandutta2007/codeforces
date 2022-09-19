#include <bits/stdc++.h>

using namespace std;
bool v[101];
bool k[101];
int n;
int main()
{
    cin >> n;
    for (int i=1; i<=100; i++) {
        v[i]=true;
    }
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        for (int j=1; j<=x; j++) {
            int a;
            cin >> a;
            k[a]=true;
        }
        for (int i=1; i<=100; i++) {
            if (!k[i]) {
                v[i]=false;
            }
            k[i]=false;
        }
    }
    for (int i=1; i<=100; i++) {
        if (v[i]) {
            cout << i << " ";
        }
    }
    return 0;
}