#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define uint unsigned int


using namespace std;

const int MAXN = 200;

bool vis[MAXN][MAXN];
char match[MAXN][MAXN];

int arr[] = {6, 5, 4, 3, 2, 1};

inline char ask(int a, int b) {
    if(vis[a][b]) {
        return match[a][b];
    }
    vis[a][b] = 1;

    cout << "? " << a + 1 << " " << b + 1 << endl;
    char ans;
    cin >> ans;
    //ans = (arr[a] > arr[b] ? '>' : '<');

    return match[a][b] = ans;
}

int main() {
#ifdef HOME
    //ifstream cin("A.in");
    //ofstream cout("A.out");
#endif
    int i, j, t, n;
    //ios::sync_with_stdio(false);
    //cin.tie(0), cout.tie(0);

    mt19937 rng(time(0));

    cin >> t;
    while(t--) {
        cin >> n;

        for(i = 0; i < 2 * n; i++) {
            for(j = 0; j < 2 * n; j++) {
                vis[i][j] = 0;
            }
        }

        auto get = [&](const vector <int> &ord) {
            int sz = ord.size();
            vector <int> deg(sz);

            for(int i = 0; i < sz; i++) {
                for(int j = 0; j < sz; j++) {
                    if(i == j) continue;

                    if(ask(ord[i], ord[j]) == '>') {
                        deg[j]++;
                    }
                    else {
                        deg[i]++;
                    }
                }
            }
            vector <int> cur;
            for(int i = 0; i < sz; i++) {
                int id = 0;
                for(int j = 0; j < sz; j++) {
                    if(deg[j] > deg[id]) {
                        id = j;
                    }
                }
                cur.push_back(ord[id]);
                deg[id] = -1;
            }

            return cur;
        };

        vector <int> a, b;
        for(i = 0; i <= n - 2; i++) {
            a.push_back(i);
        }
        for(i = n - 1; i <= n; i++) {
            b.push_back(i);
        }

        for(i = n + 1; i < 2 * n; i++) {
            a = get(a);
            b = get(b);
            if(ask(a[0], b[0]) == '>') {
                b[0] = i;
            }
            else {
                a[0] = i;
            }
        }

        a = get(a);
        b = get(b);
        ask(a[0], b[0]);

        cout << "!" << endl;
    }


    return 0;
}