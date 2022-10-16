#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <iostream>

#define X first
#define Y second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair < int, int> pii;
typedef pii pt;
typedef pair <ll, ll> pll;
typedef vector < int > v;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = (1 << LOG);
const double EPS = 1e-9;
const double PI = 3.1415926535;

set < pii >  s;
int n, k1, k2, k,a[N],b[N];

int main(){
    scanf("%d%d%d", &n, &k1, &k2);
    k = k1 + k2;
    for(int i = 0;i<n;i++)
        scanf("%d",a+i);
    for(int i = 0;i<n;i++)
        scanf("%d",b+i);
    for(int i = 0;i<n;i++)
        s.insert(MP(abs(a[i] - b[i]), i));
    for(int e = 0;e<k;e++){
        int i = s.rbegin()->second;
        s.erase(*s.rbegin());
        if(a[i] > b[i]) a[i]--;
        else a[i]++;
        s.insert(MP(abs(a[i] - b[i]), i));
    }
    ll sol = 0;
    for(int i = 0;i<n;i++)
        sol += (ll)(a[i] - b[i]) * (ll)(a[i] - b[i]);
    printf("%I64d\n",sol);
    return 0;
}