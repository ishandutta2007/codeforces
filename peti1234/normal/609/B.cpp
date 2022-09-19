#include <bits/stdc++.h>

using namespace std;
long long n, m, db[11], sum;
int main()
{
    cin >> n >> m;
    sum=n*(n-1)/2;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        sum-=db[x]++;
    }
    cout << sum << "\n";
    return 0;
}