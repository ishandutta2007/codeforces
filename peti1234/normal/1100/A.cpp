#include <bits/stdc++.h>

using namespace std;
int n, k;
int maxi=0;
int t[101];
int sum;
int main()
{
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        sum+=t[i];
    }
    for (int i=1; i<=k; i++) {
        int x=sum;
        for (int j=i; j<=n; j+=k) {
            x-=t[j];
        }
        x=abs(x);
        maxi=max(maxi, x);
    }
    cout << maxi << endl;
    return 0;
}