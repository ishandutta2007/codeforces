#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <unordered_map>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef set < int > si;

const int N = 1e3 + 50;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = (1 << LOG);
const double EPS = 1e-9;
const double PI = 3.1415926535;

unordered_map < int , int > rrank, pr, sm, bio;
int q;

int par(int x){
    if(x == pr[x]) return x;
    return par(pr[x]);
}

int xxor(int x){
    if(x == pr[x]) return 0;
    return xxor(pr[x]) ^ sm[x];
}

void mrg(int x,int y,int z){
    if(par(x) == par(y)) return;
    z = xxor(x) ^ xxor(y) ^ z;
    x = par(x);
    y = par(y);
    if(rrank[x] > rrank[y]){
        pr[y] = x;
        sm[y] = z;
        rrank[x] = max(rrank[x], rrank[y] + 1);
    }
    else{
        pr[x] = y;
        sm[x] = z;
        rrank[y] = max(rrank[y], rrank[x] + 1);
    }
}

void create(int x){
    pr[x] = x;
    sm[x] = 0;
    rrank[x] = 1;
    bio[x] = 1;
}

int main(){
    scanf("%d", &q);
    int last = 0, bla = 0;
    int ty, x, y, z;
    for(int i = 0;i<q;i++){
        scanf("%d%d%d", &ty, &x, &y);
        if(ty == 1){
            int z;scanf("%d", &z);
            x = last ^ x;
            y = last ^ y;
            z = last ^ z;
            if(x > y) swap(x, y);
            x--;
            if(!bio[x]) create(x);
            if(!bio[y]) create(y);
            mrg(x, y, z);

        }
        else{
            x = last ^ x;
            y = last ^ y;
            if(x > y) swap(x, y);
            x--;
            if(!bio[x]) create(x);
            if(!bio[y]) create(y);
            if(par(x) != par(y)){
                last = 1;
                printf("-1\n");
            }
            else{
                last = xxor(x) ^ xxor(y);
                printf("%d\n", last);
            }
        }
    }
}