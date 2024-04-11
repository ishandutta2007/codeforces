#include <bits/stdc++.h>

using namespace std;
int n;
int t[1000001];
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        t[i]=i;
    }
    for (int i=2; i<=n; i++) {
        if (t[i]==i) {
            for (int j=i; j<=n; j+=i) {
                t[j]=i;
            }
        }
    }
    int mini=n;
    for (int i=n-t[n]+1; i<=n; i++) {
        if (t[i]!=i) {
        mini=min(mini, i-t[i]+1);
        }
    }
    cout << mini << endl;
    return 0;
}