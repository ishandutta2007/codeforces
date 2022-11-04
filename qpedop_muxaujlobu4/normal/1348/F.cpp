#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<queue>
using namespace std;
const unsigned long long INF = 1e17;
const int INFi = 2e7;
const int Y = 200100;
const long long m = 1000000007;
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
struct Cyst {
    int l;
    int r;
    Cyst(long long L = 0, long long R = 0) {
        l = L;
        r = R;
    }
};
vector<pair<int, int>>End[Y];
vector<int>BG[Y];
bool vis[Y];
int ID[Y];
int ans1[Y];
int ans2[Y];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    bool aa = true;
    for (int i = 1; i <= n; ++i) {
        int l, r;
        cin >> l >> r;
        End[l].push_back({ r,i });
    }
    set<pair<int, int>>sp;
    for (int i = 1; i <= n; ++i) {
        for (auto x : End[i]) {
            sp.insert(x);
        }
        pair<int, int> T = *sp.begin();
        sp.erase(sp.begin());
        ans1[T.second] = i;
        ID[i] = T.second;
    }
    int id1 = -1, id2 = -1;
    for (int i = 1; i <= n; ++i) {
        ans2[i] = ans1[i];
        for (auto x : End[i]) {
            sp.insert(x);
        }
        pair<int, int> T = *sp.begin();
        sp.erase(sp.begin());
        if (aa && !sp.empty()) {
            pair<int, int> T1 = *sp.begin();
            if (ans1[T1.second] <= T.first) {
                aa = false;
                id1 = T1.second;
                id2 = T.second;
            }
        }
    }
    if (aa) {
        cout << "YES\n";
        for (int i = 1; i <= n; ++i) {
            cout << ans1[i] << " ";
        }
    }
    else {
        swap(ans2[id1], ans2[id2]);
        cout << "NO\n";
        for (int i = 1; i <= n; ++i)cout << ans1[i] << " ";
        cout << endl;
        for (int i = 1; i <= n; ++i)cout << ans2[i] << " ";
    }
    return 0;
}