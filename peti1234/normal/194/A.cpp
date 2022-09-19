#include <bits/stdc++.h>
 
using namespace std;
int n, k;
int main()
{
    cin >> n >> k;
    cout << max(0, 3*n-k) << endl;
    return 0;
}