#include <bits/stdc++.h>

using namespace std;
int n, m;
string a, b;

int main()
{
    cin >> a >> b;
    n=a.size(), m=b.size();
    vector<int> pref(m, n);
    vector<int> suf(m, -1);

    int pos=-1, kezd=-1, veg=m;
    for (int i=0; i<m; i++) {
        pos++;
        while (pos<n && a[pos]!=b[i]) {
            pos++;
        }
        pref[i]=pos;
        if (pos<n) {
            kezd=i;
        }
    }
    pos=n;
    for (int i=m-1; i>=0; i--) {
        pos--;
        while (pos>=0 && a[pos]!=b[i]) {
            pos--;
        }
        suf[i]=pos;
        if (pos>-1) {
            veg=i;
        }
    }
    if (pref[m-1]<n) {
        cout << b << "\n";
        return 0;
    }
    if (pref[0]==n && suf[m-1]==-1) {
        cout << "-" << "\n";
        return 0;
    }
    pos=veg;
    if (kezd+1>m-veg) {
        veg=m;
    } else {
        kezd=-1;
    }
    for (int i=0; i<m; i++) {
        while (pos<m && pref[i]>=suf[pos]) {
            pos++;
        }
        if (pos<m && pos-i<veg-kezd) {
            kezd=i, veg=pos;
        }
    }
    for (int i=0; i<=kezd; i++) {
        cout << b[i];
    }
    for (int i=veg; i<m; i++) {
        cout << b[i];
    }
    cout << "\n";
    return 0;
}