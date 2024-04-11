#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int , int > pii;
typedef pair < ll, ll > pll;
typedef vector < int > vi;

const int N = 2e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int OFF = (1 <<  18);

int tour[2 * OFF], prop[2 * OFF];
vector < int > sazA, sazB;
vector < pii > swpA, swpB;

void refresh(int x){
    if(!prop[x]) return;
    tour[x] += prop[x];
    if(x < OFF){
        prop[2 * x] += prop[x];
        prop[2 * x + 1] += prop[x];
    }
    prop[x] = 0;
}

void update(int i,int a,int b,int lo,int hi,int x){
    refresh(i);
    if(lo <= a && b <= hi){
        prop[i] += x; refresh(i);
        return;
    }
    if(a > hi || b < lo) return;
    update(2 * i, a, (a + b) / 2, lo, hi, x);
    update(2 * i + 1, (a + b) / 2 + 1, b, lo, hi , x);
    tour[i] = max(tour[2 * i], tour[2 * i + 1]);
}

int query(int i,int a,int b,int lo,int hi){
    refresh(i);
    if(lo <= a && b <= hi) return tour[i];
    if(a > hi || b < lo) return 0;
    return max(query(2 * i, a, (a + b) / 2, lo, hi), query(2 * i + 1, (a + b) / 2 + 1, b, lo, hi));
}

int as[N], ae[N], bs[N], be[N], n;

int main(){
    scanf("%d", &n);
    for(int i = 1;i <= n;i++){
        scanf("%d%d%d%d", as + i, ae + i, bs + i, be + i);
        sazA.PB(as[i]), sazA.PB(ae[i]);
        sazB.PB(bs[i]), sazB.PB(be[i]);
    }
    sort(sazA.begin(), sazA.end());
    sort(sazB.begin(), sazB.end());
    for(int i = 1;i <= n;i++){
        as[i] = lower_bound(sazA.begin(), sazA.end(), as[i]) - sazA.begin();
        ae[i] = lower_bound(sazA.begin(), sazA.end(), ae[i]) - sazA.begin();
        bs[i] = lower_bound(sazB.begin(), sazB.end(), bs[i]) - sazB.begin();
        be[i] = lower_bound(sazB.begin(), sazB.end(), be[i]) - sazB.begin();
        swpA.PB({as[i], i});
        swpA.PB({ae[i], -i});
        swpB.PB({bs[i], i});
        swpB.PB({be[i], -i});
    }
    sort(swpA.begin(), swpA.end());
    memset(tour, 0, sizeof(tour));
    memset(prop, 0, sizeof(prop));
    for(int i = 1;i <= n;i++)
        update(1, 0, OFF - 1, bs[i], be[i], 1);
    int ans = 0;
    for(int i = 0;i < 2 * n;i++){
        int j = i;
        while(j < 2 * n && swpA[i].X == swpA[j].X) j++;
        for(int k = i;k < j;k++){
            if(swpA[k].Y > 0){
                int ind = swpA[k].Y;
                update(1, 0, OFF - 1, bs[ind], be[ind], -1);
            }
        }
        for(int k = i;k < j;k++){
            if(swpA[k].Y < 0){
                int ind = -swpA[k].Y;
                if(query(1, 0, OFF - 1, bs[ind], be[ind]) > 0)
                    ans = 1;// printf("sijece se %d\n", ind);
            }
        }
        i = j - 1;

    }
    //if(ans) printf("NO\n");
    //else printf("YES\n");
    sort(swpB.begin(), swpB.end());
    memset(tour, 0, sizeof(tour));
    memset(prop, 0, sizeof(prop));
    for(int i = 1;i <= n;i++)
        update(1, 0, OFF - 1, as[i], ae[i], 1);
    for(int i = 0;i < 2 * n;i++){
        int j = i;
        while(j < 2 * n && swpB[i].X == swpB[j].X) j++;
        for(int k = i;k < j;k++){
            if(swpB[k].Y > 0){
                int ind = swpB[k].Y;
                update(1, 0, OFF - 1, as[ind], ae[ind], -1);
            }
        }
        for(int k = i;k < j;k++){
            if(swpB[k].Y < 0){
                int ind = -swpB[k].Y;
                if(query(1, 0, OFF - 1, as[ind], ae[ind]) > 0)
                    ans = 1;
            }
        }
        i = j - 1;

    }
    if(ans) printf("NO\n");
    else printf("YES\n");
    return 0;
}