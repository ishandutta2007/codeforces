#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;



int n, m, x, y;
int black[1024];
int d[1024][1024], e[1024][1024];
char s[2048];

int main() {
    scanf("%d%d%d%d", &n, &m, &x, &y);
    for (int i=0; i<n; i++) {
        scanf("%s", s);
        for (int j=0; j<m; j++) if (s[j]=='#') black[j]++;
    }
    memset(d, 0x3f, sizeof d);
    memset(e, 0x3f, sizeof e);
    for (int i=0; i<n; i++) d[0][i]=e[0][i]=m*n;
    d[0][1]=n-black[0];
    e[0][1]=black[0];

    for (int i=1; i<m; i++) {
        int mi=e[i-1][x];
        for (int j=x; j<=y; j++) mi=min(mi, e[i-1][j]);
        d[i][1]=mi+n-black[i];
        mi=d[i-1][x];
        for (int j=x; j<=y; j++) mi=min(mi, d[i-1][j]);
        e[i][1]=mi+black[i];
        for (int j=2; j<=y; j++) {
            d[i][j]=d[i-1][j-1]+n-black[i];
            e[i][j]=e[i-1][j-1]+black[i];
        }
    }
    int ans=d[m-1][x];
    for (int i=x; i<=y; i++) ans=min(ans, min(d[m-1][i], e[m-1][i]));
    printf("%d\n", ans);


    return 0;
}