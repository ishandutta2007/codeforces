#include <bits/stdc++.h>

using namespace std;

const int c=400002;
long long sum, mod=998244353;
int bal, jobb, m, w, elcnt, qcnt;
int po[c], el[c], sorkezd[c], sorveg[c];
bool akt[c], veg[c];
deque<int> q[c];
void pb(int irany, int sor, int ert) {
    if (akt[ert]) {
        sum-=po[ert];
        akt[ert]=0;
    }
    bool valt=0;
    if (irany==0) {
        valt=!akt[q[sor].front()];
        q[sor].push_front(ert);
    }
    if (irany==1) {
        valt=!akt[q[sor].back()];
        q[sor].push_back(ert);
    }
    if (valt) {
        sum+=po[ert];
        akt[ert]=1;
    }
}
void add(int a, int b) {
    elcnt++;
    int balhely=el[a], jobbhely=el[b];
    bool va=veg[a], vb=veg[b];
    veg[a]=0, veg[b]=0, el[a]=0, el[b]=0;
    if (!balhely && !jobbhely) {
        qcnt++;
        q[qcnt].push_back(elcnt);
        veg[a]=0, veg[b]=1;
        sorkezd[qcnt]=a, sorveg[qcnt]=b;
        el[a]=el[b]=qcnt;
        return;
    }
    if (!balhely || q[balhely].size()<q[jobbhely].size()) {
        swap(balhely, jobbhely);
        swap(va, vb);
        swap(a, b);
    }
    pb(va, balhely, elcnt);

    if (!jobbhely) {
        el[b]=balhely;
        veg[b]=va;
        if (va) {
            sorveg[balhely]=b;
        } else {
            sorkezd[balhely]=b;
        }
    } else {
        if (jobbhely!=balhely) {
            while (q[jobbhely].size()>0) {
                if (vb) {
                    pb(va, balhely, q[jobbhely].back());
                    q[jobbhely].pop_back();
                } else {
                    pb(va, balhely, q[jobbhely].front());
                    q[jobbhely].pop_front();
                }
            }
            int ujveg=(vb ? sorkezd[jobbhely] : sorveg[jobbhely]);
            el[ujveg]=balhely;
            veg[ujveg]=va;
            if (va) {
                sorveg[balhely]=ujveg;
            } else {
                sorkezd[balhely]=ujveg;
            }
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> bal >> jobb >> m;
    po[0]=1;
    for (int i=1; i<c; i++) {
        po[i]=(po[i-1]*2)%mod;
    }
    for (int i=1; i<=m; i++) {
        int a, b; cin >> a >> b;
        add(a, b+bal);
    }
    cin >> w;
    for (int i=1; i<=w; i++) {
        int s; cin >> s;
        if (s==1) {
            int a, b; cin >> a >> b;
            add(a, b+bal);
            sum%=mod;
            if (sum<0) {
                sum+=mod;
            }
            cout << sum << "\n";
        }
        if (s==2) {
            int db=0;
            for (int i=1; i<=elcnt; i++) {
                db+=akt[i];
            }
            cout << db << " ";
            for (int i=1; i<=elcnt; i++) {
                if (akt[i]) {
                    cout << i << " ";
                }
            }
            cout << "\n";
        }
    }
    return 0;
}