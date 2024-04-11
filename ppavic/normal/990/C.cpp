#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
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

const int N = 3e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int BASE = 31337;
const int LOG = 18;
const int OFF = (1 << LOG);
const double EPS = 1e-9;
const double PI = 3.1415926535;

map < int , int > mp[2];
char s[N];
int n;
ll sol = 0;

int main(){
    scanf("%d", &n);
    for(int i = 0;i<n;i++){
        scanf("%s", s);
        int cnt = 0, x = strlen(s), can2 = 1;
        for(int j = 0;j<x;j++){
            if(s[j] == ')') cnt--;
            else cnt++;
            if(cnt < 0) can2 = 0;
        }
        int nd = -cnt, can = 1;
        if(nd < 0) can = 0;
        for(int j = 0;j<x;j++){
            if(s[j] == ')') nd--;
            else nd++;
            if(nd < 0) can = 0;
        }
        if(can){
            sol += mp[0][-cnt];
            mp[1][cnt]++;
        }
        if(can2){
            sol += mp[1][-cnt];
            mp[0][cnt]++;
        }
    }
    printf("%lld\n", sol);
    return 0;
}