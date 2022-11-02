#include <bits/stdc++.h>

using namespace std;

//#define int long long
#define double long double
//#define mod 1000000007ll
#define INF 1000000000000000000ll

#define MAX_N 1000010

const vector<long long> mod {1000000007};
const int baza = 1 << 20;
long long p[4][baza + 10];

vector<int> v;
unsigned it;

struct drzewo {
    int size;
    vector<int> hasz;
    drzewo *left, *right;
    int pocz, kon;

    drzewo(int pocz = 0, int kon = baza) {
        this->pocz = pocz;
        this->kon = kon;
        left = right = nullptr;
        size = 0;

        for (unsigned i = 0; i < mod.size(); i++) {
            hasz.push_back(0);
        }
    }

    drzewo *push_back() {
        drzewo *res = new drzewo();
        *res = *this;

        if (pocz + 1 == kon) {
            for (unsigned i = 0; i < mod.size(); i++) {
                res->hasz[i] = v[it++];
                res->size++;
            }
            return res;
        }

        int sr = (pocz + kon) / 2;

        if (res->left == nullptr) {
            res->left = new drzewo(pocz, sr);
            res->right = new drzewo(sr, kon);
        }

        if (res->left->size != sr - pocz) {
            res->left = res->left->push_back();
        }
        if (it < v.size()) {
            res->right = res->right->push_back();
        }

        res->size = res->left->size + res->right->size;
        for (unsigned i = 0; i < mod.size(); i++) {
            res->hasz[i] = (res->left->hasz[i] * p[i][res->right->size] + res->right->hasz[i]) % mod[i];
        }
        return res;
    }

    bool operator < (const drzewo & other) const {
        if (size != other.size) {
            return size < other.size;
        }

        bool rozne = false;
        for (unsigned i = 0; i < mod.size(); i++) {
            if (hasz[i] != other.hasz[i]) rozne = true;
        }

        if (!rozne) return false;

        const drzewo *a = this;
        const drzewo *b = &other;

        while (a->pocz + 1 != b->kon) {
            rozne = false;
            for (unsigned i = 0; i < mod.size(); i++) {
                if (a->left->hasz[i] != b->left->hasz[i]) {
                    rozne = true;
                    break;
                }
            }

            if (rozne) {
                a = a->left;
                b = b->left;
            } else {
                a = a->right;
                b = b->right;
            }
        }

        return a->hasz[0] < b->hasz[0];
    }

    bool operator <= (const drzewo & other) const {
        if (size == other.size) {
            bool rozne = false;

            for (unsigned i = 0; i < mod.size(); i++) {
                if (hasz[i] != other.hasz[i]) rozne = true;
            }

            if (!rozne) return true;
        }

        return *this < other;
    }
};

vector<pair<int, int> > drogi[1000010];
drzewo dist[100010];
bool visited[1000010];

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (unsigned i = 0; i < mod.size(); i++) p[i][0] = 1;
    p[0][1] = 10;
    p[1][1] = 17;
    p[2][1] = 19;
    p[3][1] = 13;

    for (unsigned i = 0; i < mod.size(); i++) {
        for (int j = 2; j <= baza; j++) {
            p[i][j] = (p[i][j - 1] * p[i][1]) % mod[i];
        }
    }

    priority_queue<pair<drzewo, int>, vector<pair<drzewo, int> >, greater<pair<drzewo, int> > > kol;
    int n, m;
    cin >> n >> m;

    for (int a, b, i = 1; i <= m; i++) {
        cin >> a >> b;
        drogi[a].emplace_back(b, i);
        drogi[b].emplace_back(a, i);
    }

    visited[1] = true;
    kol.emplace(dist[1], 1);
    it = 0;
    v = {1};
    dist[1] = *dist[1].push_back();

  //  cout << dist[1].hasz[1] << endl;

    while (!kol.empty()) {
        drzewo odl = kol.top().first;
        int gdzie = kol.top().second;
        kol.pop();

        //cout << gdzie << " " << odl.hasz[0] << endl;
        if (visited[gdzie] && dist[gdzie] <= odl) {
            continue;
        }
        //cout << "in";

        visited[gdzie] = true;
        dist[gdzie] = odl;

        //cout << dist[gdzie].hasz[0] << endl;

        drzewo *pom;
       // cout << odl.hasz[0] << endl;
        for (pair<int, int> i : drogi[gdzie]) {
           // cout << "  " << i.first << "," << i.second;
            pom = &odl;

            //vector<int> v;
            v.clear();
            it = 0;
            while (i.second) {
                v.push_back(i.second % 10);
                i.second /= 10;
            }
            reverse(v.begin(), v.end());

            if (visited[i.first] && dist[i.first].size < odl.size + v.size()) {
                continue;
            }

            pom = pom->push_back();

            /*for (int j : v) {
                pom = pom->push_back(j);
            }*/

            kol.emplace(*pom, i.first);
           // cout << "," << pom->hasz[0];
        }
       // cout << endl;
    }

    for (int i = 2; i <= n; i++) {
        cout << dist[i].hasz[0] << "\n";
    }

    return 0;
}
/*

*/