#include <bits/stdc++.h>

using namespace std;
int q;
int n, p, k;
int t[200001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> q;
    while(q--) {
        cin >> n >> p >> k;
        int maxi=0, sum=0, ossz=0;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> t[i];
        }
        sort(t+1, t+n+1);
        for (int i=0; i<k; i++) {
            sum+=t[i];
            if (sum<=p) maxi=max(maxi, i);
            for (int j=i+k; j<=n; j+=k) {
                ossz+=t[j];
                if (sum+ossz<=p) maxi=max(maxi, j);
            }
            ossz=0;
        }
        cout << maxi << "\n";
    }
    return 0;
}