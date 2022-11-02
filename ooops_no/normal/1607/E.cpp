#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define pb push_back
#define ll long long
#define int long long

mt19937 rnd(51);

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        int l = -1, r = s.size();
        pair<int,int> p = {1, 1};
        while(r - l > 1){
            int mid = (r + l) / 2, balx = 0, baly = 0, mnx = 0, mny = 0, mxx = 0, mxy = 0;
            for (int i = 0; i <= mid; i++){
                if (s[i] == 'U') balx--;
                else if (s[i] == 'D') balx++;
                else if (s[i] == 'R') baly++;
                else baly--;
                if (balx < 0){
                    mnx = max(mnx, abs(balx));
                }
                else mxx = max(mxx, abs(balx));

                if (baly < 0){
                    mny = max(mny, abs(baly));
                }
                else mxy = max(mxy, abs(baly));
            }
            if (mnx + mxx < n && mny + mxy < m){
                l = mid;
                p = {mnx + 1, mny + 1};
            }
            else r = mid;
        }
        cout << p.first << ' ' << p.second << endl;
    }
    return 0;
}