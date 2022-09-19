#include <bits/stdc++.h>

using namespace std;
const int c=200002;
long long n, sum, maxi, t[c], kom[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> t[i];
    for (int i=2; i<=n; i++) kom[i]=t[i]+kom[i-2];
    for (int i=1; i<=n; i+=2) sum+=t[i], maxi=max(maxi, sum+kom[n-1]-kom[i-1]);
    sum=0;
    for (int i=2; i<=n; i+=2) sum+=t[i], maxi=max(maxi, sum+kom[n]-kom[i-1]);
    cout << maxi << "\n";
    return 0;
}