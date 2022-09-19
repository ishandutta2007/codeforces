#include <bits/stdc++.h>

using namespace std;
const int c=1002;
int n, t[c];
int kerd(int a, int b) {
    cout.flush() << "? " << a << " " << b  << "\n";
    int x; cin >> x;
    return x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    t[1]=kerd(2, 3);
    for (int i=2; i<=n; i++) t[i]=kerd(1, i);
    t[1]=t[3]-t[1];
    cout << "! " << t[1] << " ";
    for (int i=2; i<=n; i++) {
        cout << t[i]-t[i-1] << " ";
    }
    cout << "\n";
    return 0;
}