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
typedef vector < int > vi;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = (1 << LOG);
const double EPS = 1e-9;
const double PI = 3.1415926535;

int x,d;
vector < ll > v;

int main(){
    scanf("%d%d",&x,&d);
    ll lst = 1;
    for(;x;){
        int cur = 0;
        while(x >= (1 << cur) - 1)
            cur++;
        cur--;
        x -= (1 << cur) - 1;
        for(int i = 0;i<cur;i++)
            v.PB(lst);
        lst += d;
    }
    printf("%d\n",v.size());
    for(int i = 0;i<v.size();i++){
        printf("%lld ",v[i]);
    }
    printf("\n");
    return 0;
}