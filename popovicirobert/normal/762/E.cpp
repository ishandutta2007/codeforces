#include <bits/stdc++.h>
#define MAXF 10000
#define MAXN 100000

using namespace std;

vector < pair <int, int> > station[MAXF + 1];
vector < pair <int, int> > a;
vector < pair <int, int> > b;

vector <int> aint[4 * MAXN + 1];

inline void refresh(int nod) {
    int n = aint[2 * nod].size(), m = aint[2 * nod + 1].size();
    int i = 0, j = 0;
    aint[nod].clear();
    while(i < n && j < m) {
        if(aint[2 * nod][i] < aint[2 * nod + 1][j]) {
            aint[nod].push_back(aint[2 * nod][i]);
            i++;
        }
        else {
            aint[nod].push_back(aint[2 * nod + 1][j]);
            j++;
        }
    }
    while(i < n) {
         aint[nod].push_back(aint[2 * nod][i]);
         i++;
    }
    while(j < m) {
         aint[nod].push_back(aint[2 * nod + 1][j]);
         j++;
    }
}

void build(int nod, int left, int right) {
    if(left == right) {
        aint[nod].clear();
        aint[nod].push_back(b[left].second);
    }
    else {
        int med = (left + right) / 2;
        build(2 * nod, left, med);
        build(2 * nod + 1, med + 1, right);
        refresh(nod);
    }
}

long long ans = 0;
long long cnt = 0;

void query(int nod, int left, int right, int l, int r, int val) {
    if(l <= left && right <= r) {
        int rez1, rez2;
        rez1 = rez2 = -1;
        for(int pas = 1 << 16; pas; pas >>= 1) {
            if(rez1 + pas < aint[nod].size() && aint[nod][rez1 + pas] < val)
                rez1 += pas;
            if(rez2 + pas < aint[nod].size() && aint[nod][rez2 + pas] <= val)
                rez2 += pas;
        }
        cnt += rez2 - rez1;
        ans += aint[nod].size() - rez1 - 1;
    }
    else {
        int med = (left + right) / 2;
        if(l <= med)
            query(2 * nod, left, med, l, r, val);
        if(med < r)
            query(2 * nod + 1, med + 1, right, l, r, val);
    }
}

void clear(int nod, int left, int right) {
    aint[nod].clear();
    if(left < right) {
        int med = (left + right) / 2;
        clear(2 * nod, left, med);
        clear(2 * nod + 1, med + 1, right);
    }
}

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, k, x, r, f, j;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(i = 1; i <= n; i++) {
        cin >> x >> r >> f;
        station[f].push_back({x, r});
    }
    for(i = 1; i <= MAXF; i++) {
        a.clear();
        b.clear();
        for(j = max(i - k, 1); j <= min(i + k, MAXF); j++)
            for(auto it : station[j])
                b.push_back(it);
        for(auto it : station[i])
            a.push_back(it);
        if(!a.empty() && !b.empty()) {
            sort(b.begin(), b.end());
            build(1, 0, b.size() - 1);
            for(auto it : a) {
                int rez1, rez2;
                rez1 = rez2 = -1;
                for(int pas = 1 << 16; pas; pas >>= 1) {
                    if(rez1 + pas < b.size() && it.first - b[rez1 + pas].first > it.second)
                        rez1 += pas;
                    if(rez2 + pas < b.size() && b[rez2 + pas].first - it.first <= it.second)
                        rez2 += pas;
                }
                rez1++;
                if(rez1 <= rez2)
                    query(1, 0, b.size() - 1, rez1, rez2, it.second);
            }
            clear(1, 0, b.size() - 1);
        }
    }
   // printf("%d " ,cnt);
    cout << ans - n - (cnt - n) / 2;
    //cin.close();
    //cout.close();
    return 0;
}