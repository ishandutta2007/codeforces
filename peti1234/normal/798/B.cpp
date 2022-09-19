#include <bits/stdc++.h>

using namespace std;
int n;
int k=INT_MAX;
string s[51];
bool ugyanaz(int a, int b, int c)
{
    string x=s[a];
    string y=s[b];
    for (int i=0; i<x.size(); i++) {
        if (x[i]!=y[(i+c)%x.size()]) {
            return false;
        }
    }
    return x.size()==y.size();
}
int szamol(int x)
{
    int m=0;
    string p=s[x];
    for (int i=1; i<=n; i++) {
        for (int j=0; j<=p.size(); j++) {
            if (j==p.size()) {
                return INT_MAX;
            }
            if (ugyanaz(x, i, j)) {
                m+=j;
                j=100;
            }
        }
    }
    return m;
}
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> s[i];
    }
    for (int i=1; i<=n; i++) {
        k=min(k, szamol(i));
    }
    if (k==INT_MAX) {
        cout << -1 << endl;
        return 0;
    }
    cout << k << endl;
    return 0;
}