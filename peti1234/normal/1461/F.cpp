#include <bits/stdc++.h>

using namespace std;
const int c=100002, nagy=1e7;
int t[c], n, ans[c];
bool pl, mi, sz;
string s;
void solve(int kezd, int veg) {
    while (kezd<=veg && t[kezd]<2) {
        kezd++;
    }
    while (kezd<=veg && t[veg]<2) {
        veg--;
    }
    if (kezd==veg) {
        return;
    }
    int sum=0, pr=1;
    for (int i=kezd; i<=veg; i++) {
        sum+=t[i];
        pr=min(pr*t[i], nagy);
    }
    if (pr>=2*sum) {
        for (int i=kezd; i<veg; i++) {
            ans[i]=1;
        }
        return;
    }
    vector<int> k;
    for (int i=kezd; i<=veg; i++) {
        if (t[i]>1) {
            k.push_back(i);
        }
    }
    int si=k.size();
    int maxert=sum, id=0;
    for (int i=0; i<(1<<(si-1)); i++) {
        int ert=0, aktsz=t[k[0]];
        for (int j=1; j<si; j++) {
            if (i&(1<<(j-1))) {
                aktsz*=t[k[j]];
            } else {
                ert+=aktsz;
                aktsz=t[k[j]];
                ert+=k[j]-k[j-1]-1;
            }
        }
        ert+=aktsz;
        if (ert>maxert) {
            maxert=ert, id=i;
        }
    }
    for (int i=0; i<si-1; i++) {
        if (id&(1<<i)) {
            for (int j=k[i]; j<k[i+1]; j++) {
                ans[j]=1;
            }
        }
    }
}
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    cin >> s;
    for (int i=0; i<s.size(); i++) {
        char c=s[i];
        if (c=='-') mi=1;
        if (c=='+') pl=1;
        if (c=='*') sz=1;
    }
    if (s.size()==1) {
        for (int i=1; i<=n; i++) {
            cout << t[i];
            if (i!=n) {
                cout << s[0];
            }
        }
    } else if (!sz) {
        for (int i=1; i<=n; i++) {
            cout << t[i];
            if (i!=n) {
                cout << "+";
            }
        }
    } else if (!pl) {
        for (int i=1; i<=n; i++) {
            cout << t[i];
            if (i!=n) {
                if (t[i+1]==0) {
                    cout << "-";
                } else {
                    cout << "*";
                }
            }
        }
    } else {
        int kezd=1;
        for (int i=1; i<=n; i++) {
            if (t[i+1]==0) {
                solve(kezd, i);
                kezd=i+1;
            }
        }
        for (int i=1; i<=n; i++) {
            cout << t[i];
            if (i!=n) {
                if (ans[i]) {
                    cout << "*";
                } else {
                    cout << "+";
                }
            }
        }
    }
    cout << "\n";
    return 0;
}