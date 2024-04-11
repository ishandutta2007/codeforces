#include <bits/stdc++.h>

using namespace std;
long long sum;
int w, n, q, t[300002];
void add(int a, int b) {
    if (a==1 && t[1]>t[2]) sum+=t[a]*b;
    else if (a==n && t[n]>t[n-1]) sum+=t[a]*b;
    if (a<=1 || a>=n) return;
    if (t[a]>max(t[a-1], t[a+1])) sum+=t[a]*b;
    if (t[a]<min(t[a-1], t[a+1])) sum-=t[a]*b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> q, sum=0;
        for (int i=1; i<=n; i++) cin >> t[i];
        for (int i=1; i<=n; i++) add(i, 1);
        cout << sum << "\n";
        for (int i=1; i<=q; i++) {
            int a, b;
            cin >> a >> b;
            add(a-1, -1), add(a, -1), add(a+1, -1);
            if (b-a>2) add(b-1, -1);
            if (b-a>1) add(b, -1);
            add(b+1, -1);
            swap(t[a], t[b]);
            add(a-1, 1), add(a, 1), add(a+1, 1);
            if(b-a>2) add(b-1, 1);
            if (b-a>1) add(b, 1);
            add(b+1, 1);
            cout << sum << "\n";
        }
    }
    return 0;
}