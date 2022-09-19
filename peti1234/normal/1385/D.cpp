#include <bits/stdc++.h>

using namespace std;
int w, n; string s;
int solve(int k, int v, int a) {
    if (k+1==v) return (s[k]-'a')==a;
    int m=(k+v)/2, d1=0, d2=0;
    for (int i=k; i<m; i++) d1+=(s[i]-'a')==a;
    for (int i=m; i<v; i++) d2+=(s[i]-'a')==a;
    return max(d1+solve(m, v, a+1), d2+solve(k, m, a+1));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> s;
        cout << n-solve(0, n, 0) << "\n";
    }
    return 0;
}