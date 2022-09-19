#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> j;
vector<int> r;
int k=0;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x, y;
        cin >> x >> y;
        if (y==2) {
            r.push_back(k);
        }
        else {
            j.push_back(k);
        }
        k+=x;
    }
    if (r.size()==0) {
        cout << "Infinity";
        return 0;
    }
    int ln=r[0];
    for (int i=0; i<r.size(); i++) {
        if (r[i]>ln) {
            ln=r[i];
        }
    }
    int lk=INT_MAX;
    for (int i=0; i<j.size(); i++) {
        if (j[i]<lk) {
            lk=j[i];
        }
    }
    if (ln>=lk) {
        cout << "Impossible" << endl;
        return 0;
    }
    cout << 1899+k-ln << endl;
    return 0;
}