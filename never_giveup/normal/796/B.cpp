#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e6 + 100, inf = 1e9 + 100;

bool a[maxn];

int n, m, k;

int main(){
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    #endif // ONPC
    ios::sync_with_stdio(0);
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++){
        int x;
        scanf("%d", &x);
        a[x - 1] = 1;
    }
    int now = 0;
    for (int i = 0; i < k; i++){
        if (a[now]){
            printf("%d", now + 1);
            return 0;
        }
        int v, u;
        scanf("%d %d", &v, &u);
        v--;
        u--;
        if (now == v)
            now = u;
        else
        if (now == u)
            now = v;
    }
    printf("%d", now + 1);
}