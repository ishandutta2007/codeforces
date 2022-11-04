#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXVAL = (int) 4e6;
const int MAXN = (int) 1e5;

//int a[MAXN + 1];

int low[MAXVAL + 1];
bool vis[MAXVAL + 1];


set <int> s;

inline void prec() {
    for(int i = 2; i <= MAXVAL; i++) {
        if(low[i] == 0) {
            for(int j = i; j <= MAXVAL; j += i)
                low[j] = i;
        }
    }
    for(int i = 2; i <= MAXVAL; i++) {
        if(low[i] == i)
            s.insert(i);
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    prec();
    bool ok = 0;
    cin >> n;
    for(i = 1; i <= n; i++) {
        int val, x;
        cin >> val;
        x = val;
        bool flag = 0;
        while(x > 1) {
            int aux = low[x];
            while(low[x] == aux) {
                x /= aux;
            }
            flag |= vis[aux];
        }
        if(ok == 0) {
            if(flag == 0) {
                cout << val << " ";
                while(val > 1) {
                    int aux = low[val];
                    vis[aux] = 1;
                    s.erase(s.find(aux));
                    while(low[val] == aux) {
                        val /= aux;
                    }
                }
            }
            else {
                int j = val + 1;
                while(1) {
                    x = j;
                    flag = 0;
                    while(x > 1) {
                        int aux = low[x];
                        while(aux == low[x]) {
                            x /= aux;
                        }
                        flag |= vis[aux];
                    }
                    if(flag == 0)
                        break;
                    j++;
                }
                cout << j << " ";
                while(j > 1) {
                    int aux = low[j];
                    vis[aux] = 1;
                    s.erase(s.find(aux));
                    while(low[j] == aux) {
                        j /= aux;
                    }
                }
                ok = 1;
            }
        }
        else {
            cout << *s.begin() << " ";
            s.erase(s.begin());
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}