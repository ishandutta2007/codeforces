#include <bits/stdc++.h>

using namespace std;
const int c=400005;
vector<int> oszt[c];
void solve() {
    long long l, r;
    cin >> l >> r;
    long long len=(r-l+1), ans=len*(len-1)*(len-2)/6;
    for (int i=l; i<=r; i++) {
        long long cnt=0;
        for (auto x:oszt[i]) {
            if (l<=x && x<i) {
                cnt++;
            }
        }
        //cout << "fontos " << i << " " << cnt << "\n";
        ans-=cnt*(cnt-1)/2;
        if (i%6==0 && i/2>=l) ans--;
        if (i%15==0 && i*2/5>=l) ans--;
    }
    cout << ans << "\n";

}
int main()
{
    ios_base::sync_with_stdio(false);
    for (int i=1; i<c; i++) {
        for (int j=i; j<c; j+=i) {
            oszt[j].push_back(i);
        }
    }
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}
/*
1
8 86
*/