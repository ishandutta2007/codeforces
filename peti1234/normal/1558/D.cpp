#include <bits/stdc++.h>

using namespace std;
const int c=500005;
long long fakt[c], inv[c], mod=998244353;
long long oszt(long long a) {
    long long ans=1, p=mod-2;
    while (p) {
        if (p%2) {
            ans*=a, ans%=mod;
        }
        a*=a, a%=mod;
        p/=2;
    }
    return ans;
}
long long alatt(int a, int b) {
    if (a<0 || a<b || b<0) {
        return 0;
    }
    return fakt[a]*inv[b]%mod*inv[a-b]%mod;
}
int n, m, cnt, w, t[c], v[c];
vector<int> sz, h;
int lsb(int a) {
    return (a & (-a));
}
void add(int a, int b) {
    while (a<=n) {
        t[a]+=b;
        a+=lsb(a);
    }
}
int ask(int a) {
    int ans=0;
    while (a) {
        ans+=t[a];
        a-=lsb(a);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    fakt[0]=1, inv[0]=1;
    for (int i=1; i<c; i++) {
        fakt[i]=fakt[i-1]*i%mod;
        inv[i]=oszt(fakt[i]);
    }
    cin >> w;
    while (w--) {
        cin >> n >> m;
        for (int i=0; i<m; i++) {
            int a, b;
            cin >> a >> b;
            sz.push_back(b);
        }
        reverse(sz.begin(), sz.end());
        for (auto x:sz) {
            int lo=0, hi=n, mid;
            while (hi-lo>1) {
                mid=(hi+lo)/2;
                if (mid-ask(mid)>=x) {
                    hi=mid;
                } else {
                    lo=mid;
                }
            }
            v[hi]=1;
            h.push_back(hi);
            add(hi, 1);
            if (!v[hi+1]) {
                cnt++;
            }

        }
        cout << alatt(2*n-1-cnt, n) << "\n";

        for (auto x:h) {
            v[x]=0;
            add(x, -1);
        }
        sz.clear();
        h.clear();
        cnt=0;

    }
    return 0;
}
/*
1
5 3
3 1
4 1
5 3
*/