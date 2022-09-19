#include <bits/stdc++.h>

using namespace std;
const int c=100002, f=128;
int n, p, k, h, t[c][8];
long long regi[f], uj[f], maxi, s=-1e12;
vector<pair<int, int> > sz;
void fr(int a) {
    for (int m=0; m<h; m++) {
        for (int l=0; l<p; l++) {
            int d=(1<<l);
            if ((m&d)==0) {
                uj[m+d]=max(uj[m+d], regi[m]+t[a][l]);
            }
        }
    }
    //cout << "fr " << a << endl;
    //for (int i=0; i<h; i++) cout << uj[i] << endl;
    for (int i=0; i<h; i++) regi[i]=uj[i], uj[i]=0;
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n >> p >> k, h=(1<<p);
    for (int i=1; i<=n; i++) {
        int x; cin >> x;
        sz.push_back({x, i});
    }
    for (int i=1; i<=n; i++) {
        for (int j=0; j<p; j++) {
            cin >> t[i][j];
        }
    }
    sort(sz.rbegin(), sz.rend());
    for (int i=0; i<=p; i++) {
        for (int j=1; j<h; j++) {
            regi[j]=s;
        }
        for (int j=0; j<k+i; j++) {
            //cout << "proba " << i << " " << j << endl;
            int fi=sz[j].first, id=sz[j].second;
            for (int m=0; m<h; m++) {
                uj[m]=regi[m]+fi;
            }
            fr(id);
        }
        for (int j=0; j<h; j++) {
            //cout << j << " " << regi[j] << endl;
            if (__builtin_popcount(j)!=i) {
                regi[j]=0;
            }
            //cout << "valt " << j << " " << regi[j] << " " << i << endl;
        }
        for (int j=k+i; j<n; j++) {
            for (int m=0; m<h; m++) {
                uj[m]=regi[m];
            }
            fr(sz[j].second);
        }
        maxi=max(maxi, regi[h-1]);
        for (int i=0; i<h; i++) regi[i]=0;
    }
    cout << maxi << "\n";
    return 0;
}
/*
3 2 1
500 498 564
100002 3
422332 2
232323 1
*/