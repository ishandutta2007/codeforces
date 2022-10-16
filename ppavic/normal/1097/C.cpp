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

const int N = 5e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;

int n, m, poc[N], zav[N], pos = 0;
char s[N];

int main(){
    scanf("%d", &n);
    for(int i = 0;i<n;i++){
        scanf("%s", s);
        m = strlen(s);
        int ans = 0, gud = 1, mi = 0;
        for(int i = 0;i<m;i++){
            if(s[i] == '(') ans++;
            else ans--;
            mi = min(mi, ans);
        }
        if(ans >= 0 && mi < 0) continue;
        if(ans < 0 && mi < ans) continue;

        if(ans < 0) zav[-ans]++;
        else if(ans > 0 )poc[ans]++;
        else pos++;
    }
    int sol = 0;
    for(int i = 0;i<N;i++){
        sol += min(poc[i], zav[i]);
    }
    printf("%d\n", sol + pos / 2);
    return 0;
}