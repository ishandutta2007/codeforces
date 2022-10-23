/*
1. BA
2. CA
ha valamelyik jo onnantol brute force
3. CB
ha jo, akkor
    4. BC
    a vegen minden ures helyet a szelen levokkel kell kitolteni
    ha az elso kitolttt betu B, akkor
        5. BB
    egyebkent
        5. CC
    az eleje A

tudjuk, hogy a string A...B....C... alaku
4. AA
5. CC
ha mindketto jo, akkor kozepe BB
ha egyik sem jo, akkor
    6. BBB
    az elejen A, a vegen C lesz
ha csak az egyik jo, akkor kozepre lehet B-ket irni es a vegen brute force
*/
#include <bits/stdc++.h>

using namespace std;
int n, ans[55];
char valt(int x) {
    return (x==1 ? 'C' : x==2 ? 'H' : 'O');
}
bool kerd(vector<int> sz) {
    cout << "? ";
    for (auto x:sz) {
        cout << valt(x);
    }
    cout.flush() << endl;
    int db, si=sz.size();
    cin >> db;
    for (int i=1; i<=db; i++) {
        int pos;
        cin >> pos;
        for (int j=0; j<si; j++) {
            ans[pos+j]=sz[j];
        }
    }
    return db;
}
void valasz() {
    cout << "! ";
    for (int i=1; i<=n; i++) {
        cout << valt(ans[i]);
        ans[i]=0;
    }
    cout.flush() << endl;
    int x;
    cin >> x;
}
void brute_force() {
    int kezd=0, veg=0, cel=0;
    for (int i=1; i<=n; i++) {
        if (ans[i] && !kezd) {
            kezd=i;
        }
        if (!ans[i] && kezd && !veg) {
            veg=i-1;
        }
    }
    if (!veg) {
        veg=n;
    }
    while (true) {
        while (kezd>1 && ans[kezd-1]) {
            kezd--;
        }
        while (veg<n && ans[veg+1]) {
            veg++;
        }
        if (kezd==1 && veg==n) {
            break;
        }
        vector<int> sz;
        if (kezd>1) {
            sz.push_back(1);
            cel=kezd-1;
        }
        for (int i=kezd; i<=veg; i++) {
            sz.push_back(ans[i]);
        }
        if (kezd==1) {
            sz.push_back(1);
            cel=veg+1;
        }
        if (!ans[cel]) {
            kerd(sz);
        }
        if (!ans[cel]) {
            if (cel<kezd) {
                sz[0]=2;
            } else {
                sz.back()=2;
            }
            kerd(sz);
        }
        if (!ans[cel]) {
            ans[cel]=3;
        }
    }
}
void solve() {
    cin >> n;
    if (kerd({2, 1}) || kerd({3, 1})) {
        brute_force();
        valasz();
        return;
    }
    if (kerd({3, 2})) {
        kerd({2, 3});
        int ert=0;
        for (int i=1; i<=n; i++) {
            if (!ans[i] && ans[i-1]) {
                ans[i]=ans[i-1];
            }
            if (ans[i] && !ert) {
                ert=ans[i];
            }
        }
        kerd({ert, ert});
        for (int i=1; i<=n; i++) {
            if (!ans[i]) {
                ans[i]=1;
            }
        }
        valasz();
        return;
    }
    bool x=kerd({1, 1}), y=kerd({3, 3});
    for (int i=2; i<n; i++) {
        if (!ans[i]) {
            ans[i]=2;
        }
    }
    if (x && y) {
        for (int i=1; i<=n; i++) {
            if (!ans[i]) {
                ans[i]=2;
            }
        }
        valasz();
    }
    if (!x && !y) {
        kerd({2, 2, 2});
        if (!ans[1]) {
            ans[1]=1;
        }
        if (!ans[n]) {
            ans[n]=3;
        }
        valasz();
    }
    if (x!=y) {
        brute_force();
        valasz();
    }
}
int main()
{
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}
/*
OOHO
*/