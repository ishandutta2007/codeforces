#include <bits/stdc++.h>

using namespace std;
int n, k, w;
void v(int a) {cout << a << " ";}
void t(int a, int b) {for (int i=a+1; i<=b; i++) v(a+(i-a-1)/2);}
void s(int db, int p, int f) {
    v(f);
    if (db<2) t(p, n);
    else {
        if (db==3 && n-p==10) t(p, p+6), t(p+6, p+8), t(p+8, p+10);
        else if (db==2 && ((n-p)&(n-p-1))==0) v(p), t(p+1, p+3), v(p), t(p+4, n);
        else v(p), s(db-1, p+2, p);
    }
}
int main()
{
    cin >> n >> k, w=n&(n+1);
    if (n%2==0 || 2*k>max(0, n-3) || (w && !k) || (!w && k==1) || n==9 && k==2) { cout << "NO\n"; return 0;}
    cout << "YES\n";
    s(k, 1, 0);
    return 0;
}