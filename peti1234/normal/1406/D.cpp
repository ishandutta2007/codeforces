#include <bits/stdc++.h>

using namespace std;
const int c=100002;
long long n, q, sum, t[c], o=0;
bool e;
void add(int a, int b) {
    if (a>n) return;
    sum-=max(o, t[a]), t[a]+=b, sum+=max(o, t[a]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> t[i];
    sum+=t[1];
    for (int i=n; i>=2; i--) t[i]-=t[i-1], sum+=max(o, t[i]);
    e=(sum>0);
    cout << (sum+e)/2 << "\n";
    cin >> q;
    for (int i=1; i<=q; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a==1) sum+=c;
        else add(a, c);
        add(b+1, -c);
        e=(sum>0);
        cout << (sum+e)/2 << "\n";
    }
    return 0;
}
/*
6
-9 -10 -9 -6 -5 4
1
1 2 -10
*/