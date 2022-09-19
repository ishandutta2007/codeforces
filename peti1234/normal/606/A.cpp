#include <bits/stdc++.h>
 
using namespace std;
int a, b, c, d, e, f;
int p, h;
int main()
{
    cin >> a >> b >> c >> d >> e >> f;
    if (a>d) {
        p+=(a-d)/2;
    } else {
        h+=d-a;
    }
    if (b>e) {
        p+=(b-e)/2;
    } else {
        h+=e-b;
    }
    if (c>f) {
        p+=(c-f)/2;
    } else {
        h+=f-c;
    }
    if (p>=h) {
        cout << "yes";
    } else {
        cout << "no";
    }
    return 0;
}