#include <cstdio>

using namespace std;

const int N = 1e5 + 500;

int n, s, deg[N], cnt;

int main(){
    scanf("%d%d", &n, &s);
    for(int i = 1;i<n;i++){
        int x, y;scanf("%d%d", &x, &y);
        deg[x]++;deg[y]++;
    }
    for(int i = 1;i<=n;i++)
        if(deg[i] == 1) cnt++;
    if(n == 2) printf("%.10lf\n", (double)s);
    else printf("%.10lf\n", (double)(2 * s) / (double)cnt);
}