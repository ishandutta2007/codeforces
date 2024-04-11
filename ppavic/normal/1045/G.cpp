#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

long long sol;
int n, k, iq;
int p[MAXN], r[MAXN], q[MAXN];
int iq_lef[MAXN], iq_rig[MAXN], ofs[MAXN*3];
vector <int> saz_iq, t[MAXN*3];
vector < pair <int, int> > pos[MAXN*3], query;

void sazmi_iq () {
    sort(saz_iq.begin(), saz_iq.end());
    saz_iq.erase(unique(saz_iq.begin(), saz_iq.end()), saz_iq.end());
    for (int i=0; i<n; i++) {
        iq_lef[i] = lower_bound(saz_iq.begin(), saz_iq.end(), q[i] - k) - saz_iq.begin();
        iq_rig[i] = lower_bound(saz_iq.begin(), saz_iq.end(), q[i] + k) - saz_iq.begin();
        q[i] = lower_bound(saz_iq.begin(), saz_iq.end(), q[i]) - saz_iq.begin();
    }
    iq = saz_iq.size();
}

void build_tour (int ind) {
    ofs[ind] = 1;
    while (ofs[ind] < pos[ind].size()) ofs[ind] *= 2;
    for (int i=0; i<2*ofs[ind]; i++) {
        t[ind].push_back(0);
    }
}

void update_tour (int ind, int pp) {
    pp += ofs[ind];
    t[ind] [pp] = 1;
    pp = pp >> 1;
    while (pp) {
        t[ind] [pp] = t[ind] [pp*2] + t[ind] [pp*2 + 1];
        pp = pp >> 1;
    }
}

int upit_tour (int ind, int x, int from, int to, int low, int high) {
    //cout << "upit " << ind << " " << x << " " << from << " " << to << " " << low << " " << high << endl;
    if (to < low || high < from) return 0;
    if (from <= low && high <= to) return t[ind] [x];
    return upit_tour(ind, x*2, from, to, low, (low+high)/2) + upit_tour(ind, x*2+1, from, to, (low+high)/2+1, high);
}

int obradi (int x) {
    int res = 0;
    int lef = p[x] - r[x];
    int rig = p[x] + r[x];
    for (int ind = iq_lef[x]; ind <= iq_rig[x]; ind++) {
        if (pos[ind].empty()) continue;
        int tlef = lower_bound(pos[ind].begin(), pos[ind].end(), make_pair(lef, 0)) - pos[ind].begin();
        int trig = lower_bound(pos[ind].begin(), pos[ind].end(), make_pair(rig + 1, 0)) - pos[ind].begin() - 1;
        if (tlef <= trig) {
            res += upit_tour(ind, 1, tlef, trig, 0, ofs[ind] - 1);
        }
    }
    return res;
}

void update (int x) {
    int pp = lower_bound(pos[q[x]].begin(), pos[q[x]].end(), make_pair(p[x], x)) - pos[q[x]].begin();
    update_tour(q[x], pp);
}

void pozicije () {
    for (int i=0; i<n; i++) {
        pos[q[i]].push_back(make_pair(p[i], i));
    }
    for (int i=0; i<iq; i++) {
        if (pos[i].empty()) continue;
        sort(pos[i].begin(), pos[i].end());
        build_tour(i);
    }
}

void ispis () {
    cout << "---------" << endl;
    for (int i=0; i<iq; i++) {
        if (pos[i].empty()) continue;
        cout << i << "  ";
        for (int j=0; j<t[i].size(); j++) {
            //cout << pos[i] [j].first << " ";
            cout << j << " " << t[i] [j] << "  ";
        }
        cout << endl;
    }
}

int main () {
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        scanf("%d%d%d", &p[i], &r[i], &q[i]);
        query.push_back(make_pair(r[i], i));
        saz_iq.push_back(q[i]);
        saz_iq.push_back(q[i] + k);
        saz_iq.push_back(q[i] - k);
    }
    sazmi_iq();
    pozicije();
    sort(query.begin(), query.end());
    for (int i = query.size() - 1; i>=0; i--) {
        int x = query[i].second;
        //ispis();
        sol += obradi(x);
        update(x);
    }
    cout << sol << endl;
    return 0;
}