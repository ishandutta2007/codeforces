#include <bits/stdc++.h>
 
using namespace std;
int n, k, sum, t[105];
int main()
{
    cin >> n >> k;
for (int i=0; i<n; i++) cin>> t[i];
sort(t, t+n);
for(int i=0;i<n; i++) if (t[i]>=t[n-k] && t[i]) sum++;
cout << sum;
    return 0;
}