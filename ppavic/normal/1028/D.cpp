#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <queue>

#define X first
#define Y second
#define MP make_pair
#define PB push_back
#define TRACE(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef pair < ll, ll> pll;
typedef vector < int > vi;
typedef vector < ll > vl;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = (1 << 20);
const double EPS = 1e-9;
const double PI = 3.1415926535;

set < int > st;

int n, x, l, r;
char s[10];
ll sol = 1;

int main(){
    st.insert(-INF);
    st.insert(INF);
    sol = 1;
    l = -INF;r = INF;
    scanf("%d", &n);
    for(int i = 0;i<n;i++){
        scanf("%s", s);
        scanf("%d", &x);
        if(s[1] == 'D'){
            st.insert(x);
        }
        else{
            st.erase(x);
            if(l <= x && x <= r){
                if(x != l && x != r)
                    sol = (2LL * sol) % (ll)MOD;
                l = *(--st.upper_bound(x));
                r =  *st.upper_bound(x);
            }
            else{
                sol = 0;
            }
        }
    }
    int cnt = 0;
    for(int x : st){
        if(l <= x && x <= r) cnt++;
    }
    sol = (sol * (cnt - 1)) % (ll)MOD;
    printf("%d\n", (int)sol);
    return 0;
}