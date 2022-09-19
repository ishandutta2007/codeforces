#include <bits/stdc++.h>

using namespace std;
const int c=(1<<21), f=c/2;
int n, n2, q, cl[c], valt[c], spec[c], kezd[c], veg[c];
long long ert[c];
vector<pair<int, long long> > cl2[c];
void init(int ert) {
    n2=1;
    while (n2<=ert) n2*=2;
    for (int i=n2; i<2*n2; i++) {
        kezd[i]=veg[i]=i-n2+1;
    }
    for (int i=n2-1; i>=1; i--) {
        kezd[i]=kezd[2*i], veg[i]=veg[2*i+1];
    }
}
long long calc(int szin, int ut) {
    long long val=0;
    if (szin) {
        if (cl2[szin].size()>0) {
            val+=cl2[szin].back().second;
            int lo=-1, hi=cl2[szin].size(), mid;
            while (hi-lo>1) {
                mid=(hi+lo)/2;
                if (cl2[szin][mid].first<ut) {
                    lo=mid;
                } else {
                    hi=mid;
                }
            }
            if (lo!=-1) {
                val-=cl2[szin][lo].second;
            }
        }
    }
    return val;
}
int s(int a, int l, int r) {
    if (l>veg[a] || r<kezd[a]) {
        return 0;
    }
    if (l<=kezd[a] && veg[a]<=r) return 2;
    return 1;
}
void add(int a, int l, int r, int sz, int ii) {
    int p=s(a, l, r);
    //if (ii==3) cout << "add " << a << " " << l << " " << r << " " << sz << " " << ii << " " << p << "\n";
    if (p==0 || sz==0 && !spec[a]) return;
    spec[a]=1;
    if (p==2 && sz) {
        cl[a]=sz, valt[a]=ii;
        return;
    }
    if (p==2 && cl[a]) {
        ert[a]+=calc(cl[a], valt[a]);
        cl[a]=0, valt[a]=0, spec[a]=0;
        return;
    }
    int x=2*a, y=2*a+1;
    if (cl[a]) {
        cl[x]=cl[a], cl[y]=cl[a];
        valt[x]=valt[a], valt[y]=valt[a];
        spec[x]=1, spec[y]=1;
        cl[a]=0, valt[a]=0;
    }
    add(2*a, l, r, sz, ii), add(2*a+1, l, r, sz, ii);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    init(n);
    add(1, 1, n, 1, 0);
    for (int i=1; i<=q; i++) {
        string s;
        cin >> s;
        if (s=="Color") {
            int l, r, c;
            cin >> l >> r >> c;
            add(1, l, r, 0, i);
            add(1, l, r, c, i);
        }
        if (s=="Add") {
            int a, b;
            cin >> a >> b;
            long long ert=b;
            if (cl2[a].size()>0) ert+=cl2[a].back().second;
            cl2[a].push_back({i, ert});
        }
        if (s=="Query") {
            int x;
            cin >> x;
            int pos=x+n2-1;
            //cout << "kezd " << pos << "\n";
            long long szin=0, ut=0, val=0;
            while (pos) {
                val+=ert[pos];
                if (cl[pos]) {
                    szin=cl[pos];
                    ut=valt[pos];
                }
                pos/=2;
            }
            //cout << "kezd " << val << "\n";
            //cout << "query " << szin << " " << ut << " " << val << "\n";
            val+=calc(szin, ut);
            //cout << "valasz..................................................................... ";
            cout << val << "\n";
        }
    }
    return 0;
}
/*
5 5
Color 2 4 2
Add 2 2
Color 2 2 3
Add 3 3
Query 2
*/