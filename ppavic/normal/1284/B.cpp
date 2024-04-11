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

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, a[N], los = 0;
vector < int > v1, v2;

int main(){
    scanf("%d", &n);
    for(int i = 0;i < n;i++){
        int l; scanf("%d", &l);
        int bd = 0;
        for(int j = 0;j < l;j++){
            scanf("%d", a + j);
            if(j && a[j] > a[j - 1]) bd = 1;
        }
        if(bd){
            los++; continue;
        }
        v1.PB(a[l - 1]);
        v2.PB(a[0]);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int j = 0;
    ll sol = 0;
    for(int i = 0;i < (int)v2.size();i++){
        while(j < (int)v1.size() && v1[j] < v2[i]) j++;
        sol += (ll)j;
    }
    sol += 2LL * (ll)(los) * (ll)(n - los) + (ll)los * los;
    printf("%lld\n", sol);
    return 0;
}