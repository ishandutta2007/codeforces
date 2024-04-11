#include <bits/stdc++.h>
 
using namespace std;
int n, m;
vector<pair<int, int> > sz;
int fi, se;
int main()
{
    cin >> m >> n;
    for (int i=1; i<=n; i++) {
        int a, b;
        cin >> a >> b;
        sz.push_back({a, b});
    }
    fi=sz[0].first;
    for (int i=0; i<n; i++) {
        int a=sz[i].first;
        int b=sz[i].second;
        if (a!=fi && b!=fi) {
            if (a!=se && b!=se) {
                if (se==0) {
                    se=a;
                } else {
                    break;
                }
            }
        }
        if (i==n-1) {
            cout << "YES" << endl;
            return 0;
        }
    }
    se=0;
    for (int i=0; i<n; i++) {
        int a=sz[i].first;
        int b=sz[i].second;
        if (a!=fi && b!=fi) {
            if (a!=se && b!=se) {
                if (se==0) {
                    se=b;
                } else {
                    break;
                }
            }
        }
        if (i==n-1) {
            cout << "YES" << endl;
            return 0;
        }
    }
    se=0;
    fi=sz[0].second;
    for (int i=0; i<n; i++) {
        int a=sz[i].first;
        int b=sz[i].second;
        if (a!=fi && b!=fi) {
            if (a!=se && b!=se) {
                if (se==0) {
                    se=a;
                } else {
                    break;
                }
            }
        }
        if (i==n-1) {
            cout << "YES" << endl;
            return 0;
        }
    }
    se=0;
    for (int i=0; i<n; i++) {
        int a=sz[i].first;
        int b=sz[i].second;
        if (a!=fi && b!=fi) {
            if (a!=se && b!=se) {
                if (se==0) {
                    se=b;
                } else {
                    break;
                }
            }
        }
        if (i==n-1) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}