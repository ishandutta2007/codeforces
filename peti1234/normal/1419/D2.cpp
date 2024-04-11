#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int n, t[c], p[c], cnt, k=1;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) cin >> t[i];
    sort(t+1, t+n+1);
    for (int i=1; i<=n/2; i++) p[2*i]=t[i];
    for (int i=n/2+1; i<=n; i++) p[k]=t[i], k+=2;
    for (int i=2; i<n; i++) cnt+=(p[i]<p[i-1] && p[i]<p[i+1]);
    cout << cnt << "\n";
    for (int i=1; i<=n; i++) cout << p[i] << " ";
    cout << "\n";
    return 0;
}