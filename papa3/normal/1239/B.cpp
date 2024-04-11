#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

#define MAX_N 1000010

int tab[MAX_N];

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;

    string ss = '#' + s + s + s;

    int gdzie = 0;
    int mi = 0;

    for (int i = 1; i <= n; i++) {
        tab[i] = tab[i - 1];

        if (ss[i] == '(') tab[i]++;
        else tab[i]--;

        if (tab[i] < mi) {
            mi = tab[i];
            gdzie = i;
        }
    }

    if (tab[n] != 0) {
        cout << "0\n1 1";
        return 0;
    }

    int res = 0;

    pair<int, int> zmiana = {1, 1};

    /*if (true) {
        gdzie++;
        swap(ss[gdzie + n - 1], ss[gdzie + n]);
        zmiana = {gdzie + n - 1, gdzie + n};
        tab[gdzie] = 0;
        for (int i = gdzie + 1; i <= gdzie + n; i++) {
            tab[i] = tab[i - 1];

            if (ss[i] == '(') tab[i]++;
            else tab[i]--;

            if (tab[i] == 0) res++;

            if (tab[i] < 0) {
                res = 0;
                break;
            }
        }
    }*/

    if (res == 0) {
        //swap(ss[gdzie + n - 1], ss[gdzie + n]);
        //gdzie--;
        zmiana = {1, 1};
        tab[gdzie] = 0;
        int dod = 0;
        int pop = -1;
        int ile_2 = 0;
        for (int i = gdzie + 1; i <= gdzie + n; i++) {
            tab[i] = tab[i - 1];

            if (ss[i] == '(') tab[i]++;
            else tab[i]--;

            if (tab[i] == 0) res++;

            /*if (zmiana == make_pair(1ll, 1ll) && i < gdzie + n && ss[i + 1] == ')' && ss[i] == '(' && tab[i] == 2) {
                res++;
                zmiana = {i, i + 1};
            }*/

            if (ss[i] == ')' && pop != -1) {
                if (ile_2 > dod) {
                    dod = ile_2;
                    zmiana = {pop, i};
                }
            }

            if (tab[i] < 2) {
                pop = -1;
                ile_2 = 0;
            }

            if (tab[i] == 2 && ss[i] == '(' && pop == -1) {
                pop = i;
            }
            if (tab[i] == 2) {
                ile_2++;
            }
        }
        res += dod;
    }

    int res2 = 0;
    pair<int, int> zmiana2 = {1, 1};
    tab[gdzie] = 0;
    int ile_1 = 0;
    int pop_1 = -1;
    for (int i = gdzie + 1; i <= gdzie + n; i++) {
        tab[i] = tab[i - 1];

        //cout << ss[i];

        if (ss[i] == '(') tab[i]++;
        else tab[i]--;

        if (ss[i] == ')' && pop_1 != -1) {
            if (ile_1 > res2) {
                res2 = ile_1;
                zmiana2 = {pop_1, i};
            }
        }

        if (tab[i] < 1) {
            pop_1 = -1;
            ile_1 = 0;
        }

        if (tab[i] == 1 && ss[i] == '(' && pop_1 == -1) {
            pop_1 = i;
        }
        if (tab[i] == 1) {
            ile_1++;
        }
    }

    if (res2 > res) {
        swap(res, res2);
        swap(zmiana, zmiana2);
    }

    cout << res << "\n";
    cout << (zmiana.first - 1) % n + 1 << " " << (zmiana.second - 1) % n + 1;

    return 0;
}
/*
10
()((()()))
*/