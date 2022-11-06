#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 2e5;

int v[MAXN + 1];
int aux[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> v[i];
    }
    if(n <= 2) {
        cout << 0;
        return 0;
    }
    int ans = 1e9;
    for(int a = -1; a <= 1; a++) {
        aux[1] = v[1] + a;
        for(int b = -1; b <= 1; b++) {
            int cur = 0;
            aux[2] = v[2] + b;
            for(i = 3; i <= n; i++) {
                aux[i] = v[i];
                if(aux[i] - aux[i - 1] == aux[2] - aux[1])
                    continue;
                if(abs((aux[i] - aux[i - 1]) - (aux[2] - aux[1])) <= 1) {
                    if(aux[i] - aux[i - 1] < aux[2] - aux[1])
                        aux[i]++;
                    else
                        aux[i]--;
                }
                else {
                    cur = 1e9;
                    break;
                }
            }
            for(i = 1; i <= n; i++) {
                //if(a == 1 && b == -1)
                //printf("%d %d\n" ,aux[i], v[i]);
                cur += (aux[i] != v[i]);
            }
            ans = min(ans, cur);
        }
    }
    if(ans >= 1e9)
        ans = -1;
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}