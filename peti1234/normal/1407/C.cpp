#include <bits/stdc++.h>

using namespace std;
int n, pos=1, t[10002];
int ask(int a, int b) {
    cout.flush() << "? " <<  a << " " << b << "\n";
    int x; cin >> x;
    return x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=2; i<=n; i++) {
        int x=ask(pos, i), y=ask(i, pos);
        if (x<y) t[i]=y;
        else t[pos]=x, pos=i;
    }
    t[pos]=n;
    cout << "! ";
    for (int i=1; i<=n; i++) cout << t[i] << " ";
    cout << "\n";
    return 0;
}