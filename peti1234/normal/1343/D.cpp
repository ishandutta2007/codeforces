#include <bits/stdc++.h>

using namespace std;
int w, n, k, mini;
int t[200002], kom[400002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> k, mini=n;
        for (int i=1; i<=n; i++) cin >> t[i];
        for (int i=1; i<=2*k; i++) kom[i]=0;
        for (int i=1; i<=n/2; i++) {
            int a=t[i], b=t[n-i+1], c=a+b;
            if (a>b) swap(a, b);
            kom[1]+=2, kom[c]--, kom[c+1]++;
            kom[c-b+1]--, kom[c+k-a+1]++;
        }
        for (int i=1; i<=2*k; i++) kom[i]+=kom[i-1], mini=min(mini, kom[i]);
        cout << mini << "\n";
    }
    return 0;
}
/*
1 4 3 1 2 2 1
*/