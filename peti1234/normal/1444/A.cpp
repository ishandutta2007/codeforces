#include <bits/stdc++.h>

using namespace std;
int w;
long long a, b, am, bm, maxi;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> w;
    while(w--) {
        cin >> a >> b, bm=b, maxi=0;
        for (long long i=2; i*i<=bm; i++) {
            if (bm%i==0) {
                while(bm%i==0) {
                    bm/=i;
                }
                am=a;
                while(am%b==0) {
                    am/=i;
                }
                maxi=max(maxi, am);
            }
        }
        if (bm!=1) {
            am=a;
            while(am%b==0) {
                am/=bm;
            }
            maxi=max(maxi, am);
        }
        cout << maxi << "\n";
    }
    return 0;
}