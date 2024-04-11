#include <bits/stdc++.h>

using namespace std;
int h[100001];
int dp[100001];
int kul;
int ln;
int n;
int maxi=0;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        int a;
        cin >> a;
        dp[a]++;
        int p=dp[a];
        if (p==1) {
            kul++;
        }
        h[p]++;
        h[p-1]--;
        ln=max(ln, p);
        if (p==1 && h[ln]>=kul-1) {
            maxi=i;
        }
        if (p==ln && h[p-1]==kul-1) {
            maxi=i;
        }
        if (p==ln && h[p]==kul-1 && h[1]==1) {
            maxi=i;
        }
        if (p==ln-1 && h[p]==kul-1) {
            maxi=i;
        }
    }
    cout << maxi << endl;
    return 0;
}