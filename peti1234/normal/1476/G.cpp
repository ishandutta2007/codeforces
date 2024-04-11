#include <bits/stdc++.h>

using namespace std;

long long s1=1e10, s2=1e5;
const int c=100002, k=5000, f=1000;
int n, q, t[c];
int bal=1, jobb, kerd;
int edb, mdb;
int bb[c], jj[c], valtdb[c], kk[c], ans[c];
vector<int> spec, nagy;
int ossz[c], db[c], hdb[c];
int pos[c], regi[c], uj[c];
vector<pair<long long, int> > sz;
void add(int a, int b) {
    hdb[db[a]]--;
    db[a]+=b;
    hdb[db[a]]++;
}
void valt(int a, int b) {
    int s=pos[a], ert1=regi[a], ert2=uj[a];
    if (bal<=s && s<=jobb) {
        add(t[s], -1);
        if (b==1) t[s]=uj[a];
        else t[s]=regi[a];
        add(t[s], 1);
    } else {
        if (b==1) t[s]=uj[a];
        else t[s]=regi[a];
    }
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        ossz[t[i]]++;
    }
    for (int i=1; i<=q; i++) {
        int p;
        cin >> p;
        if (p==1) {
            edb++;
            cin >> bb[edb] >> jj[edb] >> kk[edb];
            valtdb[edb]=mdb;
            long long s=bb[edb]/k*s1+jj[edb]/k*s2+mdb;
            sz.push_back({s, edb});
        }
        if (p==2) {
            mdb++;
            cin >> pos[mdb] >> uj[mdb];
            ossz[uj[mdb]]++;
            regi[mdb]=t[pos[mdb]];
            t[pos[mdb]]=uj[mdb];
        }
    }
    for (int i=mdb; i>=1; i--) {
        t[pos[i]]=regi[i];
    }
    sort(sz.begin(), sz.end());
    for (int i=1; i<=n; i++) {
        if (ossz[i]>f) {
            spec.push_back(i);
        }
    }
    for (int i=0; i<sz.size(); i++) {
        int id=sz[i].second;
        int balcel=bb[id], jobbcel=jj[id], kerdcel=valtdb[id], kozdb=kk[id];
        while (jobb<jobbcel) {
            jobb++;
            add(t[jobb], 1);
        }
        while (bal>balcel) {
            bal--;
            add(t[bal], 1);
        }
        while (jobb>jobbcel) {
            add(t[jobb], -1);
            jobb--;
        }
        while (bal<balcel) {
            add(t[bal], -1);
            bal++;
        }
        while (kerd<kerdcel) {
            kerd++;
            valt(kerd, 1);
        }
        while (kerd>kerdcel) {
            valt(kerd, -1);
            kerd--;
        }
        nagy.clear();
        for (int i:spec) {
            if (db[i]>f) {
                nagy.push_back(db[i]);
            }
        }
        sort(nagy.begin(), nagy.end());
        int mini=c;
        int balhely=1, most=0;
        for (int i=1; i<=f; i++) {
            most+=hdb[i];
            while (most>=kozdb) {
                mini=min(mini, i-balhely);
                most-=hdb[balhely];
                balhely++;
            }
        }
        for (int i=0; i<nagy.size(); i++) {
            most++;
            while (most>=kozdb && balhely<=f) {
                mini=min(mini, nagy[i]-balhely);
                most-=hdb[balhely];
                balhely++;
            }
        }
        for (int i=kozdb-1; i<nagy.size(); i++) {
            mini=min(mini, nagy[i]-nagy[i-kozdb+1]);
        }
        if (mini==c) {
            mini=-1;
        }
        ans[id]=mini;
    }
    for (int i=1; i<=edb; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}