#include <bits/stdc++.h>

using namespace std;
int w;
long long n, m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        long long sum=n*(n+1)/2, s=n-m, alap=s/(m+1), mar=s%(m+1);
        cout << sum-(m+1-mar)*(alap)*(alap+1)/2-(mar)*(alap+1)*(alap+2)/2 << "\n";
    }
    return 0;
}