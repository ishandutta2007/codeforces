#include <bits/stdc++.h>

using namespace std;
long long h1=998244353, h2=1000000007;
long long e[100002], m[100002];
long long ek[100002], mk[100002];
long long n, x, y, k, h, kki, hki;
vector<pair<int, int> > a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int q, w, e, r;
        cin >> q >> w >> e >> r;
        a.push_back({q, -i}), a.push_back({w, i});
        b.push_back({e, -i}), b.push_back({r, i});
    }
    sort(a.begin(), a.end()), sort(b.begin(), b.end());
    for (int i=0; i<a.size(); i++) {
        long long id=a[i].second;
        long long f=id*id%h1, g=abs(id*id*id)%h2;
        if (id<0) {
            ek[-id]=kki, mk[-id]=hki;
            k+=f, k%=h1;
            h+=g, h%=h2;
        } else {
            e[id]=k+kki-ek[id], m[id]=h+hki-mk[id];
            //cout << id << " " << e[id] << " " << m[id] << "\n";
            kki+=f, kki%=h1, hki+=g, hki%=h2;
            k-=f, k+=h1, k%=h1;
            h-=g, h+=h2, h%=h2;
        }
    }
    kki=0, hki=0;
    for (int i=0; i<b.size(); i++) {
        long long id=b[i].second;
        long long f=id*id%h1, g=abs(id*id*id)%h2;
        if (id<0) {
            ek[-id]=kki, mk[-id]=hki;
            k+=f, k%=h1;
            h+=g, h%=h2;
        } else {
            e[id]-=k+kki-ek[id], m[id]-=h+hki-mk[id];
            kki+=f, kki%=h1, hki+=g, hki%=h2;
            k-=f, k+=h1, k%=h1;
            h-=g, h+=h2, h%=h2;
        }
    }
    for (int i=1; i<=n; i++) e[i]+=h1*h1, e[i]%=h1, m[i]+=h2*h2, m[i]%=h2;
    for (int i=1; i<=n; i++) {
        if (e[i] || m[i]) {
            cout << "NO" << "\n";
            return 0;
        }
    }
    cout << "YES" << "\n";
    return 0;
}