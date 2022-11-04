#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<bitset>
#include<queue>
#include<random>
using namespace std;
int gcd(int i, int j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
template<typename T> inline T getint() {
    T val = 0;
    char c;

    bool neg = false;
    while ((c = getchar()) && !(c >= '0' && c <= '9')) {
        neg |= c == '-';
    }

    do {
        val = (val * 10) + c - '0';
    } while ((c = getchar()) && (c >= '0' && c <= '9'));

    return val * (neg ? -1 : 1);
}
const long long INF = 10000000;
const int Y = 5100;
const long long mod = 1000000007;
int msk = 2047;
int ans[Y];
map<pair<int, int>, int>er;
int n;
int zI = -1;
int get(int i, int j) {
    if (er[{i, j}] != 0)return er[{i, j}];
    cout << "? " << i << " " << j << endl;
    int v;
    cin >> v;
    if (v == -1)exit(0);
    er[{i, j}] = er[{j, i}] = v;
    return v;
}
void Mrec(vector<int> qw) {
    if (qw.size() == 1) {
        zI = qw[0];
        return;
    }
    if (qw.size() == 2) {
        vector<int>bb;
        for (int i = 1; i <= n; ++i) {
            if (qw[0] != i && qw[1] != i) {
                bb.push_back(i);
            }
        }
        while (true) {
            int idx = rand() % bb.size();
            int r1 = get(bb[idx], qw[0]), r2 = get(bb[idx], qw[1]);
            if (r1 != r2) {
                if (r1 < r2) {
                    zI = qw[0];
                }
                else {
                    zI = qw[1];
                }
                return;
            }
        }
    }
    else{
        int mx = qw.size();
        int ch = 0;
        for (int i = 0; i < 20; ++i) {
            if ((mx & (1 << i)) != 0) {
                ch = i + 1;
            }
        }
        ch /= 2;
        int inter;
        while (true) {
            int id = rand() % qw.size(), id2 = rand() % qw.size() * 3 % qw.size();
            while (id == id2) {
                id2 = rand() % qw.size() * 3 % qw.size();
            }
            int r = get(qw[id], qw[id2]);
            ans[qw[id]] &= r;
            ans[qw[id2]] &= r;
            int ct = 0;
            for (int i = 0; i < 12; ++i) {
                if ((r & (1 << i)) != 0) {
                    ++ct;
                }
            }
            if (ct <= ch) {
                inter = qw[id];
                break;
            }
        }
        vector<int>nxtq;
        for (auto x : qw) {
            if (x != inter) {
                int r = get(x, inter);
                ans[inter] &= r;
                ans[x] &= r;
            }
        }
        for (int i = 1; i <= n; ++i) {
            if ((ans[i] | ans[inter]) == ans[inter])nxtq.push_back(i);
        }
        Mrec(nxtq);
    }

}
void BuildAns(int i) {
    for (int j = 1; j <= n; ++j) {
        if (j != i) {
            ans[j] = get(j, i);
        }
    }
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        ans[i] = msk;
    }
    vector<int>qw;
    for (int i = 1; i <= n; ++i) {
        qw.push_back(i);
    }
    Mrec(qw);
    ans[zI] = 0;
    BuildAns(zI);
    cout << "! ";
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
//freopen("painter.in", "r", stdin);
//freopen("painter.out", "w", stdout);
/*
3
ooo
o..
o..
*/
/* Fri May 15 2020 19:54:42 GMT+0300 (MSK) */

/* Wed May 20 2020 19:33:48 GMT+0300 (MSK) */