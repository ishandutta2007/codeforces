#include <bits/stdc++.h>

using namespace std;
const int c=500002;
long long n, t[c], bal[c], jobb[c], sol[c], pos, maxi;
vector<int> sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> t[i];
    sz.push_back(0);
    for (int i=1; i<=n; i++) {
        while(t[i]<t[sz.back()]) sz.pop_back();
        int x=sz.back();
        bal[i]=t[i]*(i-x)+bal[x];
        sz.push_back(i);
    }
    sz.clear(), sz.push_back(n+1);
    for (int i=n; i>=1; i--) {
        while(t[i]<t[sz.back()]) sz.pop_back();
        int x=sz.back();
        jobb[i]=t[i]*(x-i)+jobb[x];
        sz.push_back(i);
        long long p=bal[i]+jobb[i]-t[i];
        if (p>maxi) {
            maxi=p;
            pos=i;
        }
    }
    sol[pos]=t[pos];
    for (int i=pos-1; i; i--) {
        sol[i]=min(t[i], sol[i+1]);
    }
    for (int i=pos+1; i<=n; i++) {
        sol[i]=min(t[i], sol[i-1]);
    }
    for (int i=1; i<=n; i++) {
        cout << sol[i] << " ";
    }
    cout << "\n";
    return 0;
}