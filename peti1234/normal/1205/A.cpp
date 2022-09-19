#include <bits/stdc++.h>

using namespace std;
int n, t[200001];
int main()
{
    cin >> n;
    if (!(n%2)) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (int i=1; i<=2*n; i+=2) {
        t[i]=i;
        int x=i+n;
        if (x>2*n) {
            x-=2*n;
        }
        t[x]=i+1;
    }
    for (int i=1; i<=2*n; i++) {
        cout << t[i] << " ";
    }
    return 0;
}