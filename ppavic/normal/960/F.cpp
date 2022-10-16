#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <unordered_map>
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

unordered_map < int ,int > v[N];

void add(int i,int j, int x){
    j += 10;
    for(;j<N;j+=j&-j)
        v[i][j] = max(v[i][j], x);
}

int query(int i,int j){
    j += 9;
    int ret = 0;
    for(;j;j -= j&-j){
        ret = max(ret, v[i][j]);
    }
    return ret;
}

int n,m,a,b,c;

int main(){
    scanf("%d%d",&n,&m);
    int sol = 0;
    for(int i = 0;i<m;i++){
        scanf("%d%d%d", &a, &b, &c);
        int cur = query(a, c) + 1;
        add(b , c, cur);
        sol = max(sol, cur);
    }
    printf("%d\n",sol);
    return 0;
}