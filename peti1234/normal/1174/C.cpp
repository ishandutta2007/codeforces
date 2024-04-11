#include <bits/stdc++.h>

using namespace std;
int t[100001], n, ans=1;
int main()
{
    cin >> n;
    for (int i=2; i<=n; i++) {
        if (!t[i]) {
            for (int j=i; j<=n; j+=i) {
                t[j]=ans;
            }
            ans++;
        }
    }
    for (int i=2; i<=n; i++) {
        cout << t[i] << " ";
    }
    return 0;
}