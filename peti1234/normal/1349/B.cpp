#include <bits/stdc++.h>

using namespace std;
int n, k, w;
int t[100002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> k;
        for (int i=1; i<=n; i++) cin >> t[i];
        bool van=0, hk=0;
        for (int i=1; i<=n; i++) {
            if (t[i]==k) van=1;
            if (i<n) {
                int a=(t[i-1]>=k), b=(t[i]>=k), c=(t[i+1]>=k);
                if (a+b+c>=2) hk=1;
            }
        }
        if (van && (hk || n==1)) cout << "yes" << "\n";
        else cout << "no" << "\n";
    }
    return 0;
}
/*
1 3 2
1 2 3
*/