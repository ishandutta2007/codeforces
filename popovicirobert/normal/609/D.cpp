#include <bits/stdc++.h>
#define ll long long
#define MAXN 200000


using namespace std;

ll a[MAXN + 1], b[MAXN + 1];
int c[MAXN + 1], t[MAXN + 1];

int n, m, k, s;
vector < pair <ll, int> > v;

inline int check(int p) {
    int i;
    v.clear();
    ll mna = (1LL << 62), mnb = (1LL << 62);
    for(i = 1; i <= p; i++) {
        mna = min(mna, a[i]);
        mnb = min(mnb, b[i]);
    }
    for(i = 1; i <= m; i++) {
        if(t[i] == 1)
            v.push_back({1LL * mna * c[i], i});
        else
            v.push_back({1LL * mnb * c[i], i});
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    ll aux = s;
    for(i = 0; i < m; i++) {
        if(aux >= v[i].first) {
            aux -= v[i].first;
            cnt++;
        }
    }
    return cnt;
}


int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i;
    ios::sync_with_stdio(false);
    cin >> n >> m >> k >> s;
    for(i = 1; i <= n; i++)
        cin >> a[i];
    for(i = 1; i <= n; i++)
        cin >> b[i];
    for(i = 1; i <= m; i++)
        cin >> t[i] >> c[i];
    int rez = 0;
    for(int pas = 1 << 17; pas; pas >>= 1)
        if(rez + pas <= n && check(rez + pas) < k)
           rez += pas;
    if(rez == n) {
        cout << -1;
        return 0;
    }
    rez++;
    cout << rez << endl;
    v.clear();
    ll mna = (1LL << 62), mnb = (1LL << 62);
    int pa, pb;
    for(i = 1; i <= rez; i++) {
        mna = min(mna, a[i]);
        if(mna == a[i])
            pa = i;
        mnb = min(mnb, b[i]);
        if(mnb == b[i])
            pb = i;
    }
    for(i = 1; i <= m; i++) {
        if(t[i] == 1)
            v.push_back({1LL * mna * c[i], i});
        else
            v.push_back({1LL * mnb * c[i], i});
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    for(i = 0; i < m && cnt < k; i++) {
        if(s >= v[i].first) {
            s -= v[i].first;
            cnt++;
            if(t[v[i].second] == 1)
               cout << v[i].second << " " << pa << endl;
            else
               cout << v[i].second << " " << pb << endl;
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}