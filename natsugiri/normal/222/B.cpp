#include<cstdio>
#include<algorithm>
using namespace std;


typedef long long LL;


int n, m, k, a[1010][1010];
int row[1010], col[1010];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i=0; i<n; i++) row[i]=i;
    for (int i=0; i<m; i++) col[i]=i;

    for (int i=0; i<k; i++) {
        char s[16];
        int x, y;
        scanf("%s%d%d", s, &x, &y);
        x--; y--;
        if (s[0]=='g') {
            printf("%d\n", a[row[x]][col[y]]);
        } else if (s[0]=='c') {
            swap(col[x], col[y]);
        } else {
            swap(row[x], row[y]);
        }
    }
    return 0;
}