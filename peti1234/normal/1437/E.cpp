#include <bits/stdc++.h>

using namespace std;
const int c=500002;
int n, m, t[c], p[c], sum, pr=0;
vector<int> sz;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m, sum=m;
    for (int i=1; i<=n; i++) {
        cin >> t[i], t[i]+=n-i;
    }
    sz.push_back(0);
    for (int i=1; i<=m; i++) {
        int x; cin >> x;
        sz.push_back(x);
    }
    t[n+1]=2e9;
    sz.push_back(n+1);
    for (int i=1; i<sz.size(); i++) {
        int a=sz[i-1], b=sz[i];
        if (t[a]>t[b]) pr=-1;
        for (int i=1; i<=b-a; i++) p[i]=0;
        int pos=1, lo, hi, mid;
        for (int i=a+1; i<b; i++) {
            if (t[a]<=t[i] && t[i]<=t[b]) {
                lo=0, hi=pos+1;
                while(hi-lo>1) {
                    mid=(hi+lo)/2;
                    if (t[i]>=p[mid]) lo=mid;
                    else hi=mid;
                }
                p[lo+1]=t[i];
                if (lo==pos) pos++;
            }
        }
        sum+=pos-1;
    }
    if (pr) cout << -1 << "\n";
    else cout << n-sum << "\n";
    return 0;
}