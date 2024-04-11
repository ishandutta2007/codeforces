#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
#include <deque>
#include <iostream>
#include <ctime>

#define X first
#define Y second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int> pii;
typedef pair < ll, ll> pll;
typedef vector < int > vi;
typedef vector < ll > vll;
typedef pii pt;

const int N = 2e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int BASE = 31337;
const int LOG = 18;
const int OFF = (1 << LOG);
const double EPS = 1e-9;
const double PI = 3.1415926535;

unordered_map < int, ll > sol, sv[N];
vector < int > v[N];
int a[N], n;

void solve(int x, int lst){
    for(int y : v[x]){
        if(y == lst) continue;
        solve(y, x );
        for(auto it = sv[y].begin();it != sv[y].end();it++){
            for(auto it2 = sv[x].begin();it2 != sv[x].end();it2++){
                sol[__gcd(__gcd(it->X, a[x]),it2->X)] += (it->Y) * (it2->Y);
            }
        }
        for(auto it = sv[y].begin();it != sv[y].end();it++){
            sv[x][__gcd(a[x], it->X)] += it->Y;
        }
        sv[y].clear();
    }
    sv[x][a[x]]++;
    for(auto it = sv[x].begin();it != sv[x].end();it++)
        sol[it->X] += it->Y;
}

int main(){
    scanf("%d", &n);
    for(int i = 1;i<=n;i++)
        scanf("%d", a + i);
    for(int i = 1;i<n;i++){
        int x,y;scanf("%d%d", &x, &y);
        v[x].PB(y);v[y].PB(x);
    }
    solve(1,1);
    vector < pair < int, ll >  > fin;
    for(auto it = sol.begin();it != sol.end();it++){
        fin.PB(MP(it->X,it->Y));
    }
    sort(fin.begin(),fin.end());
    for(int i = 0;i<fin.size();i++){
        printf("%d %I64d\n", fin[i].X, fin[i].Y);
    }
    return 0;
}