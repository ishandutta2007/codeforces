#include<bits/stdc++.h>

using namespace std;

int w;
long long n, ert, kis, nagy, mini, maxi, koz, s;
bool ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        kis=0, nagy=n, ert=0, mini=0, maxi=0, s=-1;
        while (nagy-kis>1) {
            koz=(nagy+kis)/2;
            ert+=koz*s;
            s*=-1;
            mini=min(mini, ert), maxi=max(maxi, ert);
            kis=koz;
        }
        ert=1-mini;
        cout << "? " << ert << endl;
        cin >> ans;
        kis=0, nagy=n, s=-1;
        while (nagy-kis>1) {
            koz=(nagy+kis)/2;
            ert+=koz*s;
            cout << "? " << ert << endl;
            cin >> ans;
            if (ans==1) {
                nagy=koz;
            } else {
                kis=koz;
            }
            s*=-1;
        }
        cout << "= " << nagy << endl;
    }
    return 0;
}