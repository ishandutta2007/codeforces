#include <bits/stdc++.h>

using namespace std;
int n, m;
long long t[200001];
int p;
int f(int x) {
    return x+1;
}
struct cs
{
    int k;
    bool b;
    int h;
    int a;
    bool operator<(cs x) const
    {
        return k<x.k || (k==x.k && b<x.b);
    }
};

vector<cs> l;
int main()
{
    cin >> n >> m;
    for (int i=0; i<=m; i++) {
        t[i]=INT_MAX;
    }
    p=INT_MAX;
    for (int i=1; i<=n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        l.push_back({a, 0, b-a+1, c});
        l.push_back({b, 1, b-a+1, c});
    }
    sort(l.begin(), l.end());
    for (int i=0; i<l.size(); i++) {
        if (l[i].b==1) {
            t[l[i].h]=min(t[l[i].h], (long long)l[i].a);
        }
        if (l[i].b==0 && m-l[i].h>0) {
            p=min((long long)p, l[i].a+t[m-l[i].h]);
        }
    }
    if (p<=2000000000) {
        cout << p << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}