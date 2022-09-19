#include <bits/stdc++.h>

using namespace std;
const int c=200002;
long long sum=1, mod=1e9+7;
vector<pair<int, int> > pr[c];
int n, q, t[c], db[c], inv[c], cnt;
vector<pair<int, int> > s;
vector<vector<int>> sz;
vector<int> udb;
void add(int prim, int id, int ert) {
    //cout << "add " << prim << " " << id << " " << ert << "\n";
    if (db[prim]<n) {
        return;
    }
    int hely=inv[prim];
    if (!sz[hely][id]) {
        udb[hely]--;
        //cout << "torol " << hely << endl;
    }
    sz[hely][id]+=ert;
    if (!udb[hely]) {
        int mini=c;
        for (int i=0; i<n; i++) {
            mini=min(mini, sz[hely][i]);
        }
        for (int i=0; i<mini; i++) {
            sum*=prim;
            sum%=mod;
        }
        for (int i=0; i<n; i++) {
            sz[hely][i]-=mini;
            if (!sz[hely][i]) {
                udb[hely]++;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    for (int i=2; i<c; i++) {
        if (!pr[i].size()) {
            for (int j=i; j<c; j+=i) {
                int x=j, db=0;
                while (x%i==0) {
                    x/=i;
                    db++;
                }
                pr[j].push_back({i, db});
            }
        }
    }
    cin >> n >> q;
    for (int i=0; i<n; i++) {
        cin >> t[i];
        for (auto j:pr[t[i]]) {
            db[j.first]++;
        }
    }
    for (int i=1; i<=q; i++) {
        int a, b; cin >> a >> b;
        s.push_back({a-1, b});
        for (auto j:pr[b]) {
            db[j.first]++;
        }
    }
    for (int i=1; i<c; i++) {
        if (db[i]>=n) {
            inv[i]=cnt++;
            //cout << "fontos " << i << "\n";
            //cout << inv[i] << endl;
        }
    }
    sz.resize(cnt), udb.resize(cnt);
    for (int i=0; i<cnt; i++) {
        sz[i].resize(n);
        udb[i]=n;
    }
    for (int i=0; i<n; i++) {
        for (auto j:pr[t[i]]) {
            int fi=j.first, se=j.second;
            //cout << "alap " << fi << " " << i << " " << se << "\n";
            add(fi, i, se);
        }
    }
    //cout << "vege\n";
    //return 0;
    for (auto i:s) {
        int id=i.first, szam=i.second;
        for (auto j:pr[szam]) {
            int fi=j.first, se=j.second;
            //cout << "valt " << fi << " " << id << " " << se << "\n";
            add(fi, id, se);
        }
        cout << sum << "\n";
    }
    return 0;
}