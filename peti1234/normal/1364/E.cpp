#include <bits/stdc++.h>

using namespace std;
const int c=2047;
int n, id=1, ert, pos=1, ans[2052];
int kerd(int a, int b) {
    cout.flush() << "? " << a << " " << b << "\n";
    int x; cin >> x; return x;
}
int vel() {
    int x=rand(), y=rand(), z=rand();
    return ((x%n)*(y%n)+z)%n+1;
}
int teszt(int a) {
    int ans=c;
    for (int i=1; i<=13; i++) {
        int x=vel();
        if (x!=a) ans=ans&kerd(a, x);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    ert=teszt(id);
    while(pos<=n) {
        if (pos!=id) {
            int x=kerd(pos, id);
            if (x<=ert) id=pos, ert=teszt(id);
            pos++;
        } else pos++;
    }
    for (int i=1; i<=n; i++) if (i!=id) ans[i]=kerd(i, id);
    cout << "! " << "\n";
    for (int i=1; i<=n; i++) cout << ans[i] << " ";
    return 0;
}