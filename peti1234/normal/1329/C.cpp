#include <bits/stdc++.h>

using namespace std;
int t[1050002];
long long sum;
int w, h, g, n, m;
vector<int> sol;
bool f(int a) {
    if (a>n/2) {
        t[a]=0;
        return 1;
    }
    int x=t[a], y=t[2*a], z=t[2*a+1];
    if (!y && !z) {
        if (a<=m) return 0;
        else {
            t[a]=0;
            return 1;
        }
    }
    if (y>z) {
        t[a]=y;
        if (!f(2*a)) {
            t[a]=x;
            return 0;
        }
    } else {
        t[a]=z;
        if (!f(2*a+1)) {
            t[a]=x;
            return 0;
        }
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    for (int i=1; i<=w; i++) {
        cin >> h >> g;
        sol.clear(), sum=0;
        n=(1<<h)-1, m=(1<<g)-1;
        for (int i=1; i<=n; i++) cin >> t[i];
        for (int i=1; i<=m; i++) {
            while(f(i)) sol.push_back(i);
        }
        for (int i=1; i<=m; i++) sum+=t[i];
        cout << sum << "\n";
        for (int i=0; i<sol.size(); i++) cout << sol[i] << " ";
        cout << "\n";
    }
    return 0;
}
// Az alaptlet gyorsan megvolt, elrsok miatt sokat kellett debug-olni.