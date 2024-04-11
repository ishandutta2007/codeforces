#include <cstdio>
#include <vector>
#include <algorithm>

#define PB push_back
#define X first
#define Y second

using namespace std;

typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector < pii > vp;

const int N = 5e5 + 500;

int n, q, ans[N], a[N], dp[N], mor[N], koji[N], vl[N];

vp v[N];
vi mus[N];

int main(){
    scanf("%d%d", &n, &q);
    for(int i = 1;i<=n;i++){
        scanf("%d", a + i);
    }
    for(int i = 0;i<q;i++){
        int x, y;scanf("%d%d", &x, &y);
        v[x].PB({y, i});
        koji[i] = x;
    }
    vector < int > lis;
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<v[i].size();j++){
            ans[v[i][j].Y] = lower_bound(lis.begin(), lis.end(), v[i][j].X) - lis.begin();
        }
        int ind = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
        dp[i] = ind + 1;
        if(ind == lis.size())
            lis.PB(a[i]);
        else
            lis[ind] = a[i];
    }
    int mx = lis.size();
    lis.clear();
    for(int i = n;i>=1;i--){
        for(int j = 0;j<v[i].size();j++){
            ans[v[i][j].Y] += lower_bound(lis.begin(), lis.end(), -v[i][j].X) - lis.begin();
        }
        int ind = lower_bound(lis.begin(), lis.end(), -a[i]) - lis.begin();
        vl[i] += ind + dp[i];
        if(ind == lis.size())
            lis.PB(-a[i]);
        else
            lis[ind] = -a[i];
    }

    for(int i = 1;i<=n;i++){
        if(vl[i] == mx) mus[dp[i]].PB(i);
    }
    for(int i = 1;i<=n;i++){
        if(mus[i].size() == 1) mor[mus[i][0]] = 1;
    }
    /**
    printf("MORA:\n");
    for(int i = 1;i<=n;i++) printf("{%d %d %d %d}\n", mor[i], dp[i], vl[i],  a[i]);
    printf("\n");

    printf("lis %d\n", mx);
    **/
    for(int i = 0;i<q;i++){
        printf("%d\n", max(ans[i] + 1, mx - mor[koji[i]]));
    }
}