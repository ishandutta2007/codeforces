#include <bits/stdc++.h>

using namespace std;
long long a, b, c, d, x, y, z, o=0, sum;
int main()
{
    cin >> a >> b >> c >> d;
    for (int i=a; i<=b; i++) x=b+i-1, y=c+i-1, x=max(x, c), sum+=(d-c+1)*max(o, min(y-d, y-x+1)), y=min(y, max(x-1, d)), z=y-x+1, sum+=max(o, x-c)*(z), sum+=z*(z+1)/2;
    cout << sum << "\n";
    return 0;
}