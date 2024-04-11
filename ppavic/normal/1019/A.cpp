#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <map>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int> pii;
typedef pair < ll, ll> pll;
typedef vector < int > vi;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int BASE = 31337;
const ld EPS = 1e-9;
const ld PI = 3.1415926535;

int n, m, gl[N], c[N], za = 0;
vi v, koj[N];

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0;i<n;i++){
        scanf("%d%d", gl + i, c + i);
        koj[gl[i]].PB(c[i]);
        if(gl[i] == 1) za++;
    }
    for(int i = 1;i<=m;i++) sort(koj[i].begin(), koj[i].end());
    ll sol = 1e15;
    for(int j = 0;j<=n;j++){
        ll sum = 0;
        vi all;
        int nw = 0;
        for(int i = 2;i<=m;i++){
            int k = 0;
            while(koj[i].size() - k > j){
                sum += (ll)koj[i][k];
                k++;nw++;
            }
            for(int jj = k;jj< koj[i].size();jj++){
                all.PB(koj[i][jj]);
            }
        }
        sort(all.begin(), all.end());
        int jos = j + 1 - za - nw;
        if(jos > all.size()) continue;
        for(int j = 0;j<jos;j++){
            sum += (ll)all[j];
        }
        sol = min(sol, sum);
    }
    printf("%lld\n", sol);
}