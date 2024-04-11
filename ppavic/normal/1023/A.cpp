#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include <set>
#include <queue>

#define PB push_back
#define MP make_pair
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef pair < int, int> pii;
typedef pair < ll, ll> pll;
typedef vector < int > vi;
typedef vector < ll > vl;

const int N = 2e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = (1 << LOG);
const double EPS = 1e-9;
const double PI = 3.1415926535;

int n, m, gud = 1, wld;
char s[N], t[N];

int main(){
    scanf("%d%d", &n, &m);
    scanf("%s", s);
    scanf("%s", t);
    for(int i = 0;i<n;i++){
        if(s[i] == '*') wld = 1;
    }
    if(!wld){
        if(n != m){
            printf("NO\n");
            return 0;
        }
        for(int i = 0;i<n;i++){
            if(s[i] != t[i]){

            printf("NO\n");
            return 0;
            }
        }
        printf("YES\n");
        return 0;
    }
    if(n > m + 1){
        printf("NO\n");
        return 0;
    }
    int i = 0;
    while(s[i] != '*'){
        if(i >= m || s[i] != t[i]){
            printf("NO\n");
            return 0;
        }
        i++;
    }
    i = 1;
    while(s[n - i] != '*'){
        if(n - i < 0 || m - i < 0 || s[n - i] != t[m - i]){
            printf("NO\n");
            return 0;
        }
        i++;
    }
    printf("YES\n");
    return 0;
}