#include <bits/stdc++.h>

using namespace std;
const int c=100005;
int w, n, k, cnt, kezd, veg;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> k;
        cin >> s;
        cnt=0, kezd=-1, veg=-1;
        for (int i=0; i<n; i++) {
            if (s[i]=='1') {
                if (kezd==-1) kezd=i;
                veg=i;
                cnt++;
            }
        }
        if (!cnt) {
            cout << 0 << "\n";
            continue;
        }
        int sum=11*cnt;
        if (n-1-veg<=k) {
            k-=n-1-veg;
            sum-=10;
            if (cnt==1) {
                cout << sum << "\n";
                continue;
            }
        }
        if (kezd<=k) {
            sum--;
        }
        cout << sum << "\n";
    }
    return 0;
}