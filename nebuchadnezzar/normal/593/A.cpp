#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME aplusb

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

int n;
int num[26][26];
int now[26];
int num1[26];

int main() {        
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);


    cin >> n;
    //cerr << n << endl;

    for (int i = 0; i < n; ++i) {
        //cerr << i << endl;
        string s;
        cin >> s;
        memset(now, 0, sizeof now);

        for (char ch: s) {
            now[ch - 'a'] = 1;
        }

        int nnum = 0;
        vector <int> v;
        for (int j = 0; j < 26; ++j) {
            nnum += now[j];
            if (now[j]) {
                v.puba(j);
            }
        }

        if (nnum == 1) {
            num1[v[0]] += szof(s);
        }
        if (nnum == 2) {
            num[v[0]][v[1]] += szof(s);
        }
    }

    int best = 0;
    for (int i = 0; i < 26; ++i) {
        for (int j = i + 1; j < 26; ++j) {
            best = max(best, num[i][j] + num1[i] + num1[j]);
            //cerr << i << " " << j << " " << num[i][j] << endl;
        }
    }

    cout << best << endl;

    return 0;
}