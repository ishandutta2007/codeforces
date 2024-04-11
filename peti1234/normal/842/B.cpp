#include <bits/stdc++.h>

using namespace std;
int r, d;
int p;
int n;
int main()
{
    cin >> r >> d;
    cin >> n;
    for (int i=1; i<=n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        double t=sqrt(a*a+b*b);
        if (t>=r-d+c && t<=r-c) {
            p++;
        }
    }
    cout << p << endl;
    return 0;
}