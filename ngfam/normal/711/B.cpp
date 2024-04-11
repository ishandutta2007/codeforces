#include <bits/stdc++.h>
#define prob "test"
typedef long long llint;
using namespace std;
void MAIN();
int main(){
    #ifndef ONLINE_JUDGE
        freopen(prob".inp","r",stdin);
      //  freopen(prob".out","w",stdout);
    #endif
    MAIN();
    return 0;
}
const llint N = 5e2 + 1, mod = 1e9 + 7;

int n; llint a[N][N], rs, row[N], col[N], l, r, curcol, currow, curl, curr, cal, base;
vector < llint > fk;

void no(){
    printf("-1");
    exit(0);
}

void MAIN(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j){
            scanf("%I64d", &a[i][j]);
            if(a[i][j] == 0){
                 currow = i;
                 curcol = j;
                 if(i == j) curl = i;
                 if(j == n - i + 1) curr = i;
            }
            else {
                row[i] += a[i][j];
                col[j] += a[i][j];
                if(i == j) l += a[i][j];
                if(j == n - i + 1) r += a[i][j];
            }
        }
    for(int i = 1; i <= n; ++i){
        if(i != currow) fk.push_back(row[i]);
        if(i != curcol) fk.push_back(col[i]);
    }
    if(curl == 0) fk.push_back(l);
    if(curr == 0) fk.push_back(r);

    llint ans;
    if(fk.size() > 0)  ans = fk[0] - col[curcol];
    else {
        printf("1");
        return;
    }
    if(ans <= 0) no();
    fk.push_back(col[curcol] + ans);
    fk.push_back(row[currow] + ans);
    if(curl) fk.push_back(l + ans);
    if(curr) fk.push_back(r + ans);

    for(int i = 1; i < fk.size(); ++i)
        if(fk[i] != fk[i - 1]) no();
    printf("%I64d", ans);
}