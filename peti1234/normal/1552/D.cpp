#include <bits/stdc++.h>

using namespace std;
int w, n, t[10], sum, jo;
int main()
{
    cin >> w;
    while (w--) {
        cin >> n;
        jo=0;
        for (int i=0; i<n; i++) {
            cin >> t[i];
        }
        int s=1;
        for (int i=0; i<n; i++) {
            s*=3;
        }
        for (int i=1; i<s; i++) {
            sum=0;
            int ii=i;
            for (int j=0; j<n; j++) {
                if (ii%3==1) {
                    sum+=t[j];
                }
                if (ii%3==2) {
                    sum-=t[j];
                }
                ii/=3;
            }
            if (sum==0) {
                jo=1;
            }
        }
        cout << (jo ? "YES" : "NO") << "\n";
    }
    return 0;
}