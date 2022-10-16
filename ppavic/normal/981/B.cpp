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

int bio[N][2];
vi v;
map < int , int > cost[2];
int n,m;
ll sol = 0;


int main(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        int x,y;scanf("%d%d",&x,&y);
        cost[0][x] = y;
        v.PB(x);
    }

    scanf("%d",&m);
    for(int i = 0;i<m;i++){
        int x,y;scanf("%d%d",&x,&y);
        cost[1][x] = y;
        v.PB(x);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int j = 0;j<v.size();j++){
        int i = v[j];
        sol += (ll)max(cost[0][i], cost[1][i]);
    }
    printf("%I64d\n", sol);
    return 0;
}