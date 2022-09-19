#include <bits/stdc++.h>

using namespace std;
const int c=10000002;
int p[c], a[500002], b[500002], n;
int main()
{
    for (int i=2; i<c; i++) if (!p[i]) for (int j=i; j<c; j+=i) if (!p[j]) p[j]=i;
    cin >> n, p[1]=2;
    for (int i=1; i<=n; i++) {
        int x, y, z=1; cin >> x, y=p[x];
        while(x%y==0) x/=y, z*=y;
        a[i]=x, b[i]=z;
        if (x==1) a[i]=-1, b[i]=-1;
    }
    for (int i=1; i<=n; i++) cout << a[i] << " ";
    cout << "\n";
    for (int i=1; i<=n; i++) cout << b[i] << " ";
    cout << "\n";
    return 0;
}