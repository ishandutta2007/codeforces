#include <bits/stdc++.h>

using namespace std;
int n, k, cnt=0, po=1;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    while (po<n) {
        po*=k;
        cnt++;
    }
    cout << cnt << "\n";
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            int ii=i, jj=j, ert=1;
            while (true) {
                if (jj%k>ii%k) {
                    cout << ert << " ";
                    break;
                }
                ii/=k, jj/=k;
                ert++;
            }
        }
    }
    return 0;
}