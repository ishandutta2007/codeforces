#include <bits/stdc++.h>

using namespace std;
const int c=10000001;
int ans[c], inv[c], w, n;
int main()
{
    for (int i=1; i<c; i++) {
        for (int j=i; j<c; j+=i) {
            ans[j]+=i;
        }
    }
    for (int i=c-1; i>=1; i--) {
        if (ans[i]<c) {
            inv[ans[i]]=i;
        }
    }
    cin >> w;
    while (w--) {
        cin >> n;
        cout << (inv[n] ? inv[n] : -1) << "\n";
    }
    return 0;
}