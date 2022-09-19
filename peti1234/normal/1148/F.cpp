#include <bits/stdc++.h>

using namespace std;
const int c=300002;
long long n, val[c], mask[c], sum, sum2, ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> val[i] >> mask[i];
        sum+=val[i];
    }
    for (long long po=1, i=0; i<=61; i++, po*=2) {
        sum2=0;
        for (int j=1; j<=n; j++) {
            if (po<=mask[j] && mask[j]<2*po) {
                sum2+=val[j];
            }
        }
        if (!sum2) {
            continue;
        }
        if ((sum>0)==(sum2>0)) {
            ans+=po;
            for (int j=1; j<=n; j++) {
                if (po & mask[j]) {
                    val[j]*=-1;
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}