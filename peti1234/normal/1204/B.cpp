#include <bits/stdc++.h>
 
using namespace std;
int n, m, k;
int main()
{
    cin >> n >> m >> k;
    cout << (1<<m)+n-m-1 << " " << (1<<k)-1+(n-k)*(1<<(k-1)) << endl;
    return 0;
}