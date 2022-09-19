#include <bits/stdc++.h>

using namespace std;
bool jo[2522];
long long n, k=2520, db, ans;
int main()
{
    for (int i=1; i<=k; i++) {
        jo[i]=1;
        for (int j=2; j<=10; j++) if (i%j==0) jo[i]=0;
        db+=jo[i];
    }
    cin >> n;
    ans=n/k*db, n%=k;
    for (int i=1; i<=n; i++) ans+=jo[i];
    cout << ans << "\n";
    return 0;
}