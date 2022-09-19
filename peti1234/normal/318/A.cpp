#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    long long n, k, a=0;
    cin >> n >> k;
 
    if (2*k<=n+1) a=2*k-1;
    else a=2*(k-(n+1)/2);
    cout << a << endl;
    return 0;
}