#include <bits/stdc++.h>

using namespace std;
int n, k;
int sum;
int main()
{
    cin >> n >> k;
    sum=min(k-1, n-k);
    cout << sum+3*n << "\n";
    return 0;
}