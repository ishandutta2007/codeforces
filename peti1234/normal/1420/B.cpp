#include <bits/stdc++.h>

using namespace std;
int w, n, t[100002];
long long pos, el, ans=0, po;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n, el=0, ans=0, pos=0, po=1;
        for (int i=1; i<=n; i++) cin >> t[i];
        t[n+1]=2e9;
        sort(t+1, t+n+1);
        while(pos<=n) {
            while(t[pos+1]>=po) {
                ans+=(pos-el)*(pos-el-1)/2;
                el=pos, po*=2;
            }
            pos++;
        }
        cout << ans << "\n";
    }
    return 0;
}