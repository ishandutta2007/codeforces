#include <cstdio>
#include <iostream>
#include <ctime>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <vector>
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
const int MAXK = 1e5 + 5, MAXN = 1e5 + 5;

struct up {
    int type;
    LL ki, b;
    int num;
    up() {
        type = -1;
        ki = b = 0;        
    }
    up(int _type, int _ki, int _b, int _num) {
        type = _type;
        ki = _ki;
        b = _b;
        num = _num;
    }
};

bool cmp1(up u1, up u2) {
    return u1.b < u2.b;
}

LL start[MAXK], arrnewb[MAXN];
LL arrb2[MAXN];

int before[MAXN];

bool cmp2(up u1, up u2) {
    return u1.b * start[u2.ki] < u2.b * start[u1.ki];
}

bool cmp4(up u1, up u2) {
    int tmp1 = 0, tmp2 = 0;
    if (u1.type == 1) {
        tmp1 = u1.b - start[u1.ki];
    } else {
        tmp1 = u1.b;
    }
    if (u2.type == 1) {
        tmp2 = u2.b - start[u2.ki];
    } else {
        tmp2 = u2.b;
    }
    //arrb2[u1.num] = tmp1;
    //arrb2[u2.num] = tmp2;
    return tmp1 < tmp2;
}

bool cmp3(up u1, up u2) {
    long double tmp1 = 0;
    if (u1.type == 3) {
        tmp1 = u1.b;
    } else {
        tmp1 = (arrb2[u1.num] + arrnewb[u1.num]) / (long double) arrnewb[u1.num];
    }
    long double tmp2 = 0;
    if (u2.type == 3) {
        tmp2 = u2.b;
    } else {
        tmp2 = (arrb2[u2.num] + arrnewb[u2.num]) / (long double) arrnewb[u2.num];
    }
    /*
    if (u1.type == 3 && u2.type == 3) {
        return cmp1(u1, u2);
    }
    if (u2.type == 3 && u1.type != 3) {
        return arrb2[u1.num] < u2.b * arrnewb[u1.num];
    }
    if (u1.type == 3 && u2.type != 3) {
        return u1.b * arrnewb[u2.num] < arrb2[u2.num];
    }
    
    
    if (u1.ki == u2.ki) {
        return false;
    }
    
    if (u1.type == 1 || u1.type == 2) {
        return arrb2[u1.num] * arrnewb[u2.num] < arrb2[u2.num] * arrnewb[u1.num];
    }
    */
    return tmp1 < tmp2;            
    assert(false);
}

bool cmp_ans(up u1, up u2) {
    return u1.type < u2.type;
}

int k, n, m;

pair <LL, int> maxup[MAXN];

vector <up> opl, oprod, ost;

vector <up> forone[MAXK];

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    //cin >> k >> n >> m;
    scanf("%d%d%d", &k, &n, &m);

    for (int i = 0; i < k; ++i) {
        //cin >> start[i];
        scanf("%I64d", &start[i]);
    }
    for (int i = 0; i < n; ++i) {
        int type, ki, b;
        //cin >> type >> ki >> b;
        scanf("%d%d%d", &type, &ki, &b);
        --ki;
        if (type == 1) {
            maxup[ki] = max(maxup[ki], mapa((LL) b, i));            
        } else if (type == 2) {
            opl.puba(up(type, ki, b, i));
            arrb2[i] = b;
        } else {
            if (b > 1) {
                oprod.puba(up(type, ki, b, i));
            }
        }
    }

    
    //sort(bend(oprod), cmp1);
    for (int i = 0; i < k; ++i) {
        if (maxup[i].ff > start[i]) {
            ost.puba(up(1, i, maxup[i].ff, maxup[i].ss));
            arrb2[maxup[i].ss] = maxup[i].ff - start[i];
        }
    }

    //sort(bend(ost), cmp2);
    /*
    for (int i = 0; i < szof(ost); ++i) {
        cout << ost[i].b / (double) start[ost[i].ki] << " ";
    }
    cout << endl;
    */

    for (int i = 0; i < szof(ost); ++i) {
        forone[ost[i].ki].puba(ost[i]);
    }
    for (int i = 0; i < szof(opl); ++i) {
        forone[opl[i].ki].puba(opl[i]);
    }

    for (int i = 0; i < k; ++i) {
        //cout << szof(forone[i]) << endl;
        sort(bend(forone[i]), cmp4);
        reverse(bend(forone[i]));
        LL now = start[i];
        for (int j = 0; j < szof(forone[i]); ++j) {
            
            //forone[i][j].newb = now;
            arrnewb[forone[i][j].num] = now;
            before[forone[i][j].num] = j;
            now += arrb2[forone[i][j].num];
        }
        reverse(bend(forone[i]));
    }
    
    /*
    for (int i = 0; i < n; ++i) {
        cout << arrb2[i] << " " << arrnewb[i] << endl;
    }*/

    //if (szof(opl) == 0) {
    vector <up> tot;
    
    /*
    for (int i = 0; i < szof(opl); ++i) {
        tot.puba(opl[i]);
    }*/
    for (int i = 0; i < szof(oprod); ++i) {
        tot.puba(oprod[i]);
    }
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < szof(forone[i]); ++j) {
            tot.puba(forone[i][j]);
        }
    }

    //random_shuffle(bend(tot));

    sort(bend(tot), cmp3);
    vector <up> ans;
    for (int i = 0; i < m && i < szof(tot); ++i) {
        ans.puba(tot[szof(tot) - 1 - i]);
    }
    sort(bend(ans), cmp_ans);
    cout << szof(ans) << endl;
    for (int i = 0; i < szof(ans); ++i) {
        cout << ans[i].num + 1 << " ";
    }
    cout << endl;
    //return 0;
    //}

    //cout << "3\n2 3 4\n";

    return 0;
}