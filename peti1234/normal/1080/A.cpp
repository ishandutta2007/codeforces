#include <bits/stdc++.h>

using namespace std;
int n, k;
int sum;
int main()
{
    cin >> n >> k;
    sum+=(n*2-1)/k+1;
    sum+=(n*5-1)/k+1;
    sum+=(n*8-1)/k+1;
    cout << sum << endl;
    return 0;
}