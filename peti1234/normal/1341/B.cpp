#include <bits/stdc++.h>

using namespace std;
int w, n, k, a, b, cnt;
int t[200002];
bool jo(int a) {
    return (t[a]>t[a-1] && t[a]>t[a+1]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> k, a=1, b=0, k-=2, cnt=0;
        for (int i=1; i<=n; i++) cin >> t[i];
        for (int i=2; i<2+k; i++) cnt+=jo(i);
        b=cnt;
        for (int i=k+2; i<n; i++) {
            cnt+=jo(i), cnt-=jo(i-k);
            if (cnt>b) b=cnt, a=i-k;
        }
        cout << b+1 << " " << a << "\n";
    }
    return 0;
}