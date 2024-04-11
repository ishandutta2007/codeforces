#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

#define ll long long

int n, m;
int d[101010];
set<pair<int, int> > s[20];
ll q[20];

ll peelo(ll x) {
    return x*(x+1)/2;
}

void lisaa(int k, int b) {
    if (s[b].size() == 0) {
        s[b].insert(make_pair(k, k));
        q[b]++;
        return;
    }
    auto l = s[b].lower_bound(make_pair(k, k));
    auto u = s[b].upper_bound(make_pair(k, k));
    auto x = u;
    if (l != s[b].end() && (*l).first == k+1 && u != s[b].begin()) {
        u--;
        if ((*u).second == k-1) {
            s[b].insert(make_pair((*u).first, (*l).second));
            q[b] -= peelo((*l).second-(*l).first+1);
            q[b] -= peelo((*u).second-(*u).first+1);
            q[b] += peelo((*l).second-(*u).first+1);
            s[b].erase(l);
            s[b].erase(u);
            return;
        }
    }
    u = x;
    if (l != s[b].end() && (*l).first == k+1) {
        s[b].insert(make_pair(k, (*l).second));
        q[b] -= peelo((*l).second-(*l).first+1);
        q[b] += peelo((*l).second-(*l).first+2);
        s[b].erase(l);
        return;
    }
    if (u != s[b].begin()) {
        u--;
        if ((*u).second == k-1) {
            s[b].insert(make_pair((*u).first, k));
            q[b] -= peelo((*u).second-(*u).first+1);
            q[b] += peelo((*u).second-(*u).first+2);
            s[b].erase(u);
            return;
        }
    }
    s[b].insert(make_pair(k, k));
    q[b]++;
}

void poista(int k, int b) {
    auto l = s[b].lower_bound(make_pair(k, k));
    if (l == s[b].end() || (*l).first != k) l--;
    if ((*l).first == (*l).second) {
        s[b].erase(l);
        q[b]--;
        return;
    }
    if ((*l).first == k) {
        s[b].insert(make_pair(k+1, (*l).second));
        q[b] -= peelo((*l).second-(*l).first+1);
        q[b] += peelo((*l).second-(*l).first);
        s[b].erase(l);
        return;
    }
    if ((*l).second == k) {
        s[b].insert(make_pair((*l).first, k-1));
        q[b] -= peelo((*l).second-(*l).first+1);
        q[b] += peelo((*l).second-(*l).first);
        s[b].erase(l);
        return;
    }
    s[b].insert(make_pair((*l).first, k-1));
    s[b].insert(make_pair(k+1, (*l).second));
    q[b] -= peelo((*l).second-(*l).first+1);
    q[b] += peelo(k-1-(*l).first+1);
    q[b] += peelo((*l).second-(k+1)+1);
    s[b].erase(l);
}

void muuta(int k, int x) {
    for (int i = 0; i < 20; i++) {
        int a = d[k]&(1<<i);
        int b = x&(1<<i);
        if (a == b) continue;
        if (a && !b) poista(k, i);
        if (!a && b) lisaa(k, i);
    }
    d[k] = x;
}

ll laske() {
    ll t = 0;
    for (int i = 0; i < 20; i++) {
        t += q[i]*(1<<i);
    }
    return t;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        muuta(i, a);
    }
    for (int i = 0; i < m; i++) {
        int p, v;
        cin >> p >> v;
        muuta(p-1, v);
        cout << laske() << endl;
    }
}