#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector < ll > vl;
typedef pair < ll, ll > pll;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;

char s1, s2;


int main(){
    scanf(" %c %c", &s1, &s2);
    int ans = 0;
    for(int i = 0;i<5;i++){
        char x, y;scanf(" %c %c", &x, &y);
        if(x == s1 || y == s2) ans = 1;
    }
    if(ans) printf("YES\n");
    else printf("NO\n");
    return 0;
}