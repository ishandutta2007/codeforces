#include <bits/stdc++.h>

using namespace std;
int n, s, pr[100002];
int main()
{
    cin >> n, n++;
    for (int i=2; i<=n; i++) {
        if (!pr[i]) {
            pr[i]=1;
            for (int j=2*i; j<=n; j+=i) pr[j]=2, s=1;
        }
    }
    cout << s+1 << "\n";
    for (int i=2; i<=n; i++) cout << pr[i] << " ";
    return 0;
}