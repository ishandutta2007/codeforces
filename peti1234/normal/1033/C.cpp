#include <bits/stdc++.h>

using namespace std;
const int c=100002;
int n, t[c], inv[c];
bool v[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        inv[t[i]]=i;
    }
    for (int i=n; i>=1; i--) {
        int pos=inv[i];
        for (int j=pos-i; j>=1; j-=i) {
            if (!v[j] && t[j]>t[pos]) {
                v[pos]=1;
            }
        }
        for (int j=pos+i; j<=n; j+=i) {
            if (!v[j] && t[j]>t[pos]) {
                v[pos]=1;
            }
        }
    }
    for (int i=1; i<=n; i++) {
        cout << (v[i] ? "A" : "B");
    }
    cout << "\n";
    return 0;
}