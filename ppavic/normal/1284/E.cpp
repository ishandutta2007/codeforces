#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
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
typedef pair < int , int > pt;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

inline ll ccw(pt A, pt B, pt C){
    return (ll)A.X * (B.Y - C.Y) + (ll)B.X * (C.Y - A.Y) + (ll)C.X * (A.Y - B.Y);
}

pt PIVOT;


bool cmp(pt A, pt B){
    if(A.Y > PIVOT.Y && B.Y < PIVOT.Y) return 1;
    if(A.Y < PIVOT.Y && B.Y > PIVOT.Y) return 0;
    if(A.Y == PIVOT.Y && A.X < PIVOT.X && B.Y < PIVOT.Y) return 1;
    if(B.Y == PIVOT.Y && B.X < PIVOT.X && A.Y < PIVOT.Y) return 0;
    if(A.Y == PIVOT.Y && A.X > PIVOT.X && B.Y > PIVOT.Y) return 0;
    if(B.Y == PIVOT.Y && B.X > PIVOT.X && A.Y > PIVOT.Y) return 1;
    return ccw(A, B, PIVOT) <= 0LL;
}

ll choose4(int n){
    return (ll)n * (ll)(n - 1) * (ll)(n - 2) * (ll)(n - 3) / 24LL;
}

ll choose3(int n){
    return (ll)n * (ll)(n - 1) * (ll)(n - 2) / 6LL;
}

vector < pt > v, V;
int n;

int main(){
    scanf("%d", &n);
    for(int i = 0;i < n;i++){
        pt TMP; scanf("%d%d", &TMP.X, &TMP.Y);
        V.PB(TMP); v.PB(TMP);
    }
    ll ans = 0;
    for(int i = 0;i < n;i++){
        PIVOT = V[i];
        v.erase(find(v.begin(), v.end(), PIVOT));
        sort(v.begin(), v.end(), cmp);
        //printf("PIVOT %d %d\n", PIVOT.X, PIVOT.Y);
        int k = 0;
        for(int j = 0;j + 1 < n;j++){
            if(k == j) k = (j + 1) % (n - 1);
            while(ccw(v[j], v[k], PIVOT) < 0LL){
                k = (k + 1) % (n - 1);
            }
            int ln = k - j;
            if(k < j)
                ln = (n - 1) - (j - k);
            if(k == j)
                ln = n - 1;
            if(ln >= 4)
                ans += choose3(ln - 1);
            //printf("j, k = %d,%d ln = %d st = {%d %d}\n", j, k, ln, v[j].X, v[j].Y);
        }
        v.PB(PIVOT);
    }
    ans = (ll)n * choose4(n - 1) - ans;
    printf("%lld\n", ans);
}