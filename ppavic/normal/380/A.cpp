#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

#define X first
#define Y second
#define PB push_back
#define TRACE(x) printf("%s = %d\n", #x, x);

using namespace std;

typedef long long ll;
typedef pair < int , int > pii;
typedef vector < int > vi;
typedef vector < pii > vp;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = (1 << LOG);

int m;
set < pair < pair < ll, ll >, int > > S;
map < ll , int > mp;
vector < int > V;

int main(){
    scanf("%d", &m);
    ll cur = 0;
    for(int i = 0;i < m;i++){
        int ty, x, l, c;
        scanf("%d", &ty);
        if(ty == 1){
            scanf("%d", &x);
            mp[cur++] = x;
            V.PB(x);
        }
        else{
            scanf("%d%d", &l, &c); ll st = cur;
            S.insert({{cur + l * c, cur}, l}); cur += (ll)l * c;
            for(;(ll)V.size() < N && (ll)V.size() < cur;){
                V.PB(V[((ll)V.size() - st) % l]);
            }
        }
    }
    int Q; scanf("%d", &Q);
    for(int i = 0;i < Q;i++){
        ll q; scanf("%lld", &q); q--;
        if(mp[q]){
            printf("%d ", mp[q]);
        }
        else if(q < N){
            printf("%d ", V[q]);
        }
        else{
            pair < pair < ll, ll > , int > tmp = *S.lower_bound({{q, 0}, {0}});
            printf("%d ", V[(q - tmp.X.Y) % (ll)tmp.Y]);
        }
    }
    return 0;
}