#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <deque>

#define X first
#define Y second
#define INP(x) scanf("%d",&(x))
#define OUT(x) printf("%d\n",(x))
#define INP2(x,y) scanf("%d%d",&(x),&(y))
#define OUT2(x,y) printf("%d %d\n",(x),(y))
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair < int,int> pii;
typedef vector < int > vi;
typedef pii pt;
typedef pair < ll,ll> pll;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const int BASE = 31337;
const int LOG = 20;
const int OFF = (1 << LOG);
const double EPS = 1e-9;
const double PI = 3.1415926535;

string s = "";

int main(){
    cin >> s;
    int n = s.size();
    int sol = -1;
    for(int msk = 0;msk<(1 << n);msk++){
        int ret = 0;
        for(int j = 0;j<s.size();j++){
            if(msk&(1 << j))
                ret = ret * 10 + s[j] - '0';
            if(ret == 0 && (msk&(1 << j)))
                ret = -1;
        }
        if(ret > 0 && (int)sqrt(ret) * (int)sqrt(ret) == ret){
            sol = max(sol, __builtin_popcount(msk));
        }
    }
    if(sol ==  -1) OUT(-1);
    else OUT(n - sol);
    return 0;
}