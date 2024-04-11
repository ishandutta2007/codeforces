#include <bits/stdc++.h>

using namespace std;
int a, b, c;
int s=0;
int m=0;
int main()
{
    cin >> a >> b >> c;
    s+=a+b+c;
    m=max(m, a);
    m=max(m, b);
    m=max(m, c);
    s-=2*m;
    s*=-1;

    s++;
    cout << max(0, s);
    return 0;
}