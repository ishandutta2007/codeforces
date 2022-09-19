#include <bits/stdc++.h>

using namespace std;
long long a, b, c, sok=1e10, t[4];
void f(long long x) {
    cout.flush() << x << "\n";
    int p;
    cin >> p;
    if (p==1) a+=x;
    if (p==2) b+=x;
    if (p==3) c+=x;
}
int main()
{
    cin >> a >> b >> c;
    cout << "First\n";
    f(2*sok), f(3*sok);
    t[1]=a, t[2]=b, t[3]=c;
    sort(t+1, t+4);
    f(2*t[3]-t[2]-t[1]);
    t[1]=a, t[2]=b, t[3]=c;
    sort(t+1, t+4);
    f(t[2]-t[1]);
    return 0;
}