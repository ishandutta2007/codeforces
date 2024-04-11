#include <bits/stdc++.h>

using namespace std;
int w, n;
long long sum, mini, t[300002], s[300002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n;
        sum=0, mini=1000000000001;
        for (int i=1; i<=n; i++) {
            cin >> t[i] >> s[i];
            sum+=t[i];
        }
        t[n+1]=t[1];
        for (int i=1; i<=n; i++) {
            long long p=min(s[i], t[i+1]);
            sum-=p, mini=min(mini, p);
        }
        cout << sum+mini << "\n";
    }
    return 0;
}
// Minimumrtket jl kell belltani, egybknt knnyen ment.