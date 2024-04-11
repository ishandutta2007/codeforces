#include <bits/stdc++.h>

using namespace std;
long long sum, p, k, s, n, x, y, kis, nagy, o=0;
set<int> a, b, c, d;
int main()
{
    cin >> n;
    d.insert(INT_MAX), c.insert(INT_MAX), a.insert(0), b.insert(INT_MAX);
    for (int i=1; i<=n; i++) {
        auto k1=a.begin(), k2=b.begin(), k3=c.begin(), k4=d.begin();
        cin >> x >> y, sum+=y, kis=-(*k3), nagy=*k4, s=0;
        if (x==0) {
            if (y>0) {
                a.insert(-y);
                if (y>=nagy) d.erase(nagy), c.insert(-nagy), d.insert(y), p+=y-nagy;
                else c.insert(-y);
            } else {
                a.erase(y), y*=-1;
                if (y>=nagy) d.erase(y), c.erase(-kis),d.insert(kis), p-=y-kis;
                else c.erase(-y);
            }
        } else {
            if (y>0) {
                b.insert(y);
                if (y>kis) d.insert(y), p+=y;
                else c.insert(-y), c.erase(-kis), d.insert(kis), p+=kis;
            } else {
                y*=-1, b.erase(y);
                if (y>=nagy) d.erase(y), p-=y;
                else c.erase(-y), c.insert(-nagy), d.erase(nagy), p-=nagy;
            }
        }
        k1=a.begin(), k2=b.begin(), kis=-(*k1), nagy=*k2;
        if (nagy!=INT_MAX) s=max(o, nagy-kis);
        cout << sum+p-s << "\n";
    }
    return 0;
}