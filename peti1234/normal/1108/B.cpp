#include <bits/stdc++.h>

using namespace std;
int n;
int t[100001];
int maxi, k;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        maxi=max(maxi, x);
        t[x]++;
    }
    for (int i=1; i<=10000; i++) {
        if (maxi%i==0) {
            t[i]--;
        }
        if (t[i]!=0) {
            k=i;
        }
    }
    cout << maxi << " " << k << endl;
    return 0;
}