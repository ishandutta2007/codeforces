#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
const int MAXN = 2e5 + 5, MAXM = 5e5 + 5;

int n, q;
int h[MAXN];
LL howmuch[MAXM];
bool used[MAXN];
int nownum = 0;

int main() {    
    //freopen("inp", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n >> q;

    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    LL ans = 0;

    for (int i = 0; i < q; ++i) {
        int num;
        cin >> num;
        --num;
        int sign = 1;
        if (used[num]) {
            sign = -1;
            --nownum;
        }

        vector <int> v;
        int tmp = h[num];
        for (int j = 2; j * j <= tmp; ++j) {
            if (tmp % j == 0) {
                v.puba(j);
            }
            while (tmp % j == 0) {
                tmp /= j;
            }
        }

        if (tmp != 1) {
            v.puba(tmp);
        }

        int bdv = 1 << szof(v);

        int sum = 0;
        for (int j = 1; j < bdv; ++j) {
            int sumd = 0;
            int tmp = j;
            int number = 1;
            for (int k = 0; k < szof(v); ++k) {
                sumd += tmp & 1;
                if (tmp & 1) {
                    number *= v[k];
                    //cerr << v[k] << " ";
                }
                tmp >>= 1;
            }
            //cerr << number << endl;
            tmp = j;
            int add = -1;
            if (sumd & 1) {
                add = 1;
            }
            if (used[num]) {
                howmuch[number] += sign;
            }
            sum += add * howmuch[number];
            if (!used[num]) {
                howmuch[number] += sign;
            }
        }

        //cerr << sign << " " << nownum << " " << sum << endl;

        ans += sign * (nownum - sum);

        cout << ans << endl;
        
        if (!used[num]) {
            ++nownum;
        }
        used[num] = !used[num];
        /*
        for (int j = 1; j <= 6; ++j) {
            cerr << howmuch[j] << " ";
        }
        cerr << endl;*/
    }

    return 0;
}