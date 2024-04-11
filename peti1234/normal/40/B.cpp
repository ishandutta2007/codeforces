#include <bits/stdc++.h>

using namespace std;
int n, m, k, p;
int main()
{
    cin >> n >> m >> k;
    n-=2*k-2, m-=2*k-2;
    if (n>1 && m>1) p=((n-2)*(m-2)+1)/2;
    if (n<0 || m<0) cout << 0;
    else cout << (n*m+1)/2-p << "\n";
    return 0;
}