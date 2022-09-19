#include <bits/stdc++.h>

using namespace std;
const int c=1000005;
long long n, t[c], kel[c], kkov[c], nel[c], nkov[c], ans;
vector<int> sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    sz.push_back(0);
    for (int i=1; i<=n; i++) {
        while (sz.back()>0 && t[i]<t[sz.back()]) sz.pop_back();
        kel[i]=sz.back();
        sz.push_back(i);
    }
    sz.clear();
    sz.push_back(0);
    for (int i=1; i<=n; i++) {
        while (sz.back()>0 && t[i]>t[sz.back()]) sz.pop_back();
        nel[i]=sz.back();
        sz.push_back(i);
    }
    sz.clear();
    sz.push_back(n+1);
    for (int i=n; i>=1; i--) {
        while (sz.back()<n+1 && t[i]<=t[sz.back()]) sz.pop_back();
        kkov[i]=sz.back();
        sz.push_back(i);
    }
    sz.clear();
    sz.push_back(n+1);
    for (int i=n; i>=1; i--) {
        while (sz.back()<n+1 && t[i]>=t[sz.back()]) sz.pop_back();
        nkov[i]=sz.back();
        sz.push_back(i);
    }
    sz.clear();
    for (int i=1; i<=n; i++) {
        ans+=((nkov[i]-i)*(i-nel[i])-(kkov[i]-i)*(i-kel[i]))*t[i];
    }
    cout << ans << "\n";
    return 0;
}