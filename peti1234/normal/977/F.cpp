#include <bits/stdc++.h>

using namespace std;
int n, t[200005], kezd, h;
map<int, int> m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        m[t[i]]=max(m[t[i]], m[t[i]-1]+1);
        if (m[t[i]]>h) {
            kezd=t[i]-m[t[i]]+1, h=m[t[i]];
        }
    }
    cout << h << "\n";
    for (int i=1; i<=n; i++) {
        if (t[i]==kezd) {
            cout << i << " ";
            kezd++;
        }
    }
    cout << "\n";
    return 0;
}