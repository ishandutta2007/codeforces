#include <cstdio>
#include <iostream>
#include <ctime>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
const int MAXN = 205;

int m, k;
map <int, int> id;
vector <int> revid;
//vector <int> graph[MAXN];
bool graph[MAXN][MAXN];
int tmp[MAXN];

bool cmp(int a, int b) {
    return revid[a] < revid[b];
}

vector <pair <int, vector <int> > > rans;

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> m >> k;

    int c = 0;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        if (!id.count(a)) {
            id[a] = c;
            revid.puba(a);
            ++c;
        }
        if (!id.count(b)) {
            id[b] = c;
            revid.puba(b);
            ++c;
        }
        graph[id[a]][id[b]] = graph[id[b]][id[a]] = 1;
    }                           

    for (int i = 0; i < c; ++i) {
        memset(tmp, 0, sizeof tmp);
        vector <int> ans;
        int numf = 0;
        for (int j = 0; j < c; ++j) {
            if (graph[i][j]) {
                ++numf;
                for (int k = 0; k < c; ++k) {
                    if (graph[j][k]) {
                        tmp[k]++;
                    }
                }
            }
        }
        //cout << numf << " " << revid[i] << endl;
        
        for (int j = 0; j < c; ++j) {
            //cout << tmp[j] << " ";
            if (i != j && !graph[i][j] && tmp[j] * 100 >= k * numf) {
                ans.puba(j);
            }
        }
        //cout << endl;
        rans.puba(mapa(revid[i], ans));
    }

    sort(bend(rans));

    for (int i = 0; i < c; ++i) {
        cout << rans[i].ff << ": " << szof(rans[i].ss) << " ";
        sort(bend(rans[i].ss), cmp);
        for (int j = 0; j < szof(rans[i].ss); ++j) {
            cout << revid[rans[i].ss[j]] << " ";
        }
        cout << endl;
    }
    return 0;
}