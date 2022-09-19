#include <bits/stdc++.h>

using namespace std;
int n, m;
int q[13];
int qq[13];
vector<pair<int, int> > v;
vector<pair<int, int> > w;
int e(int a, int b)
{
    if (v[a].first==w[b].first && v[a].second==w[b].second) {
        return 0;
    }
    if (v[a].first==w[b].first || v[a].first==w[b].second /*|| v[a].second==w[b].first || v[a].second==w[b].second*/) {
        return 1;
    }
    if (v[a].second==w[b].first || v[a].second==w[b].second /*|| v[a].second==w[b].first || v[a].second==w[b].second*/) {
        return 2;
    }
    return 0;
}
int ee(int a, int b)
{
    if (w[a].first==v[b].first && w[a].second==v[b].second) {
        return 0;
    }
    if (w[a].first==v[b].first || w[a].first==v[b].second /*|| v[a].second==w[b].first || v[a].second==w[b].second*/) {
        return 1;
    }
    if (w[a].second==v[b].first || w[a].second==v[b].second /*|| v[a].second==w[b].first || v[a].second==w[b].second*/) {
        return 2;
    }
    return 0;
}
int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        int a, b;
        cin >> a >> b;
        if (a>b) {
            swap(a, b);
        }
        v.push_back({a, b});
    }
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        if (a>b) {
            swap(a, b);
        }
        w.push_back({a, b});
    }
    for (int i=0; i<n; i++) {
        int x=0, y=0;
        for (int j=0; j<m; j++) {
            if (e(i, j)==1) {
                x=1;
            }
            if (e(i, j)==2) {
                y=1;
            }
        }
        if (x==1 && y==1) {
            cout << -1 << endl;
            return 0;
        }
        if (x==1) {
            q[i]=1;
        }
        if (y==1) {
            q[i]=2;
        }
    }
    for (int i=0; i<m; i++) {
        int x=0, y=0;
        for (int j=0; j<n; j++) {
            if (ee(i, j)==1) {
                x=1;
            }
            if (ee(i, j)==2) {
                y=1;
            }
        }
        if (x==1 && y==1) {
            cout << -1 << endl;
            return 0;
        }
        if (x==1) {
            qq[i]=1;
        }
        if (y==1) {
            qq[i]=2;
        }
    }
    int a=-1;
    for (int i=0; i<n; i++) {
        if (q[i]!=0) {
            if (q[i]==1) {
                a=v[i].first;
            } else {
                a=v[i].second;
            }
            break;
        }
    }
    for (int i=0; i<n; i++) {
        if (q[i]!=0) {
            if (q[i]==1) {
                if (a!=v[i].first) {
                    cout << 0 << endl;
                    return 0;
                }
            } else {
                if (a!=v[i].second) {
                    cout << 0 << endl;
                    return 0;
                }
            }
        }
    }
    for (int i=0; i<m; i++) {
        if (qq[i]!=0) {
            if (qq[i]==1) {
                if (a!=w[i].first) {
                    cout << 0 << endl;
                    return 0;
                }
            } else {
                if (a!=w[i].second) {
                    cout << 0 << endl;
                    return 0;
                }
            }
        }
    }
    cout << a << endl;
    return 0;

}
/*
1 2
1 2
1 3 1 4 */
/*11 10
1 2 3 4 5 6 7 8 9 10 11
1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000*/