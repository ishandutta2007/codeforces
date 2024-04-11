#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <iostream>

#define X first
#define Y second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector < int > vi;
typedef vector < ll > vll;
typedef pair < int,int> pii;
typedef pair < double, double> pdd;
typedef pair < ll, ll > pll;

const int N = 3e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = (1 << LOG);
const ld EPS = 1e-10;
const ld PI = 3.1415926535897932384626433832795028;

vi v[N];
vector < pii > sol;
int dep[N], n;

int check(int x, int lst){
    int ret = 0, cnt = 0;
    for(int y : v[x]){
        if(y != lst){
            cnt++;
            ret = check(y, x);
        }
    }
    if(cnt >= 2) return 0;
    if(ret != 0) return ret;
    if(ret == 0 && cnt != 0) return 0;
    return x;
}

int main(){
    scanf("%d", &n);
    for(int i = 1;i<n;i++){
        int x,y;scanf("%d%d",&x,&y);
        v[x].PB(y);
        v[y].PB(x);
        dep[x]++,dep[y]++;
    }
    for(int i = 1;i<=n;i++){
        if(dep[i] > 2 || i == n){
            for(int y : v[i]){
                int s = check(y, i);
                if(s == 0){
                    printf("No\n");
                    return 0;
                }
                sol.PB(MP(i, s));
            }
            printf("Yes\n%d\n",sol.size());
            for(pii a : sol){
                printf("%d %d\n",a.X,a.Y);
            }
            return 0;
        }
    }
    return 0;
}