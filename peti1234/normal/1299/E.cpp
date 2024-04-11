#include <bits/stdc++.h>

using namespace std;
const int c=805;
int n, ans[c], rem[c][10], ee;
bool v[c], kesz[c];
vector<int> spec, kell={2, 3, 4, 5, 7, 8};
int veg1, veg2;
bool kerd() {
    int db=0;
    for (int i=1; i<=n; i++) {
        db+=v[i];
    }
    cout << "? " << db << " ";
    for (int i=1; i<=n; i++) {
        if (v[i]) {
            cout << i << " ";
        }
    }
    cout.flush() << endl;
    bool ans;
    cin >> ans;
    return ans;
}
bool kerd2(vector<int> sz) {
    cout << "? " << sz.size() << " ";
    for (auto x:sz) {
        cout << x << " ";
    }
    cout.flush() << endl;
    bool ans;
    cin >> ans;
    return ans;
}
void szel() {
    veg1=0, veg2=0;
    for (int i=1; i<=n; i++) {
        if (v[i]) {
            v[i]=0;
            if (kerd()) {
                if (!veg1) {
                    veg1=i;
                } else {
                    veg2=i;
                }
            }
            v[i]=1;
        }
    }
    return;
}
vector<int> keres(int db, int mar) {
    int mod=db+1;
    mar%=mod;
    for (int i=0; i<(1<<10); i++) {
        if (__builtin_popcount(i)!=db) {
            continue;
        }
        int sum=0;
        vector<int> res;
        for (int j=0; j<10; j++) {
            if (i & (1<<j)) {
                sum+=ans[spec[j]];
                res.push_back(spec[j]);
            }
        }
        if (sum%mod==mar) {
            return res;
        }
    }

}
void mar(int pos, int ert) {
    if (ert%2==0) {
        vector<int> sz=keres(ert-1, ert-rem[pos][ert/2]);
        sz.push_back(pos);
        rem[pos][ert]=rem[pos][ert/2];
        if (!kerd2(sz)) {
            rem[pos][ert]+=ert/2;
        }
        return;
    }
    for (int i=1; i<ert; i++) {
        vector<int> sz=keres(ert-1, i);
        sz.push_back(pos);
        if (kerd2(sz)) {
            rem[pos][ert]=ert-i;
            return;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    srand(time(0));
    cin >> n;
    for (int i=1; i<=n; i++) {
        v[i]=1;
    }
    for (int i=1; i<=5; i++) {
        if (2*i>n) {
            break;
        }
        szel();
        if (i==1) {
            ee=veg1;
        } else {
            if (kerd2({ee, veg1}) != (i%2)) {
                swap(veg1, veg2);
            }
        }
        ans[veg1]=i, ans[veg2]=n-i+1;
        v[veg1]=0, v[veg2]=0;
        spec.push_back(veg1), spec.push_back(veg2);
    }
    for (int i=1; i<=n; i++) {
        if (v[i]) {
            for (auto x:kell) {
                mar(i, x);
            }
            for (int j=1; j<=n; j++) {
                bool jo=1;
                for (auto x:kell) {
                    if (rem[i][x]!=(j%x)) {
                        jo=0;
                    }
                }
                if (jo) {
                    ans[i]=j;
                }
            }
        }
    }
    cout << "! ";
    for (int i=1; i<=n; i++) {
        cout << (ans[1]<=n/2 ? ans[i] : n+1-ans[i]) << " ";
    }
    cout << "\n";
    return 0;
}