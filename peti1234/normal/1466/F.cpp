#include <bits/stdc++.h>

using namespace std;
const int c=1e6+2;
long long ans=1, mod=1e9+7;
vector<int> sol;
int n, m, ki[c];
int holvan(int a) {
    if (!ki[a]) {
        return a;
    }
    int x=holvan(ki[a]);
    ki[a]=x;
    return x;
}
bool unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    if (a!=b) {
        ki[a]=b;
        return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        int k, a, b;
        cin >> k >> a;
        if (k==2) {
            cin >> b;
        } else {
            b=a;
        }
        if (k==1) {
            if (unio(a, m+1)) {
                ans*=2, ans%=mod;
                sol.push_back(i);
            }
        } else {
            if (unio(a, b)) {
                ans*=2, ans%=mod;
                sol.push_back(i);
            }
        }
    }
    cout << ans << " " << sol.size() << "\n";
    for (int i:sol) {
        cout << i << " ";
    }
    return 0;
}