#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

#define X first
#define Y second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;
typedef vector < int > vi;
typedef set < int > si;

const int N = 3e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = (1 << LOG);

int n, m, x[N], y[N], pref[N], pref2[N], nw[5000][2], ol[5000][2], dp[2000][200][2];
vi cen;
vector < pii > v;

inline int sum(int l,int r){
    if(r < l) return 0;
    return pref[r] - (l ? pref[l - 1] : 0);
}

inline int sum2(int l,int r){
    if(r < l) return 0;
    l = max(l, 0);
    r = min(r, N - 1);
    return pref2[r] - (l ? pref2[l - 1] : 0);
}

inline int get(int x,int y){
    int l;
    if(x < y){
        l = v[y].X - sum(x , y - 1);
    }
    else{
        l = v[y].X + sum(y, x - 1);
    }
    return sum2(l, l + v[x].Y - 1);
}

int f(int x,int cn,int fl){
    if(cn == cen.size()) return 0;
    if(x == n) return 0;
    if(dp[x][cn][fl] != -1) return dp[x][cn][fl];
    int ret = f(x + 1, cn, 1) + get(x, cen[cn]);
    if(x > cen[cn] || !fl)
        ret = max(ret, f(x, cn + 1, 0));
    return dp[x][cn][fl] = ret;

}

void iterativno(){
    for(int x = n - 1;x >= 0;x--){
        for(int cn = cen.size() - 1;cn >= 0;cn--){
            if(x < cen[cn]){
                nw[cn][1] = ol[cn][1] + get(x, cen[cn]);
            }
            else{
                nw[cn][1] = max(ol[cn][0], ol[cn][1]) + get(x, cen[cn]);
            }
            if(x <= cen[cn])
                nw[cn][0] = max(nw[cn][0], nw[cn][1]);
            nw[cn][0] = max(nw[cn][0], nw[cn + 1][0]);
        }
        for(int i = 0;i<cen.size();i++)
            for(int j = 0;j<2;j++)
                swap(nw[i][j], ol[i][j]);
    }
}


int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0;i<n;i++){
        scanf("%d", x + i);
    }
    sort(x, x + n);
    v.push_back({x[0], 1});
    for(int i = 1;i<n;i++){
        if(v.back().X + v.back().Y == x[i])
            v.back().Y++;
        else
            v.push_back({x[i], 1});
    }
    n = v.size();
    v.push_back({INF, INF});
    for(int i = 0;i<n;i++){
        pref[i] = (i ? pref[i - 1] : 0) + v[i].Y;
    }
    for(int i = 0;i<m;i++){
        scanf("%d", y + i);
        pref2[y[i]]++;
    }
    for(int i = 1;i<N;i++) pref2[i] += pref2[i - 1];
    sort(y, y + m);
    int j = 0;
    for(int i = 0;i<m;i++){
        while(j < n && v[j].X + v[j].Y - 1 < y[i]) j++;
        if(j != n){
            if(v[j].X > y[i] && j != 0)
                cen.push_back(j - 1);
            cen.push_back(j);
        }
    }
    sort(cen.begin(), cen.end());
    cen.erase(unique(cen.begin(), cen.end()), cen.end());
    iterativno();
    /**
    if(n < 2000){
        memset(dp, -1, sizeof(dp));
        printf("%d\n", f(0,0,0));
        return 0;
    }
    **/
    printf("%d\n", ol[0][0]);
}