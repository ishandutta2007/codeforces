#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long n, q, t[c], ert[c], pref[c], ans[c], l[c], r[c], fen[c][2], mod=1e9+7;
vector<pair<long long, int> > sz;
int lsb(int a) {
    return (a & -a);
}
void add(int a, int b, long long val) {
    val=(val%mod+mod)%mod;
    while (a<=n) {
        fen[a][b]=(fen[a][b]+val)%mod;
        a+=lsb(a);
    }
}
long long ask(int a, int b) {
    long long ans=0;
    while (a) {
        ans=(ans+fen[a][b])%mod;
        a-=lsb(a);
    }
    return ans;
}
long long f(long long a) {
    return (a%mod+mod)%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        cin >> ert[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        pref[i]=pref[i-1]+t[i];
    }
    for (int i=1; i<=n; i++) {
        add(i, 0, -ert[i]*t[i]);
        sz.push_back({pref[i-1], -i});
        sz.push_back({pref[i], -i});
    }
    for (int i=1; i<=q; i++) {
        cin >> l[i] >> r[i];
        sz.push_back({pref[r[i]], i});
    }
    sort(sz.begin(), sz.end());
    for (auto p:sz) {
        long long v=p.first, id=p.second, val=f(v);
        if (id<0) {
            id*=-1;
            bool st=(v==max(pref[id-1], pref[id]));
            int h=(t[id]>0 ? 1 : -1);
            if (st==0) {
                add(id, 1, 2*ert[id]*h);
                add(id, 0, -2*ert[id]*val*h);
            }
            if (st==1) {
                val=f(min(pref[id-1], pref[id]));
                add(id, 1, -2*ert[id]*h);
                add(id, 0, 2*ert[id]*val*h);
                add(id, 0, 2*ert[id]*t[id]);
            }
        }
        else {
            int bal=l[id]-1, jobb=r[id];
            ans[id]=f(ask(jobb, 0)-ask(bal, 0)+f(ask(jobb, 1)-ask(bal, 1))*val);
        }
    }
    for (int i=1; i<=q; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}