#include <bits/stdc++.h>

using namespace std;
const int c=100002;
int n, t[c], kom[c], s[c], b[c], maxi;
void solve(int k, int v, int e) {
    if (e<0 || k>v) return;
    s[k]=kom[k-1], b[v]=kom[v];
    for (int i=k+1; i<=v; i++) s[i]=min(s[i-1], kom[i-1]);
    for (int i=v-1; i>=k; i--) b[i]=max(b[i+1], kom[i]);
    int el=k;
    for (int i=k; i<=v; i++) if (t[i]==e) maxi=max(maxi, b[i]-s[i]-e), solve(el, i-1, e-1), el=i+1;
    solve(el, v, e-1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> t[i], kom[i]+=kom[i-1]+t[i];
    solve(1, n, 30);
    cout << maxi << "\n";
    return 0;
}