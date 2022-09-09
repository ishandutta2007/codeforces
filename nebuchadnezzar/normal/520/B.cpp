#include <cstdio>
#include <iostream>
#include <ctime>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
const int MAXN = 1e5;

const int MAX_MEM = (int)250 * 1024 * 1024;

int mpos, max_mpos;
char memory[MAX_MEM];                        

inline void * operator new (size_t n) {
  char *res = memory + mpos;
  mpos += n;
  assert(mpos <= MAX_MEM);
  return (void *)res;
}

inline void operator delete (void *) { }

int n, m;
queue <pii > q;
int dist[MAXN];

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n >> m;
    q.push(mapa(n, 0));
    memset(dist, -1, sizeof dist);
    dist[n] = 0;
    while (true) {
        pii p = q.front();
        q.pop();
        if (p.ff == m) {
            cout << p.ss << endl;
            return 0;
        }
        dist[p.ff] = p.ss;
        if (p.ff < m) {
            if (dist[p.ff * 2] == -1) {
                q.push(mapa(p.ff * 2, p.ss + 1));
            }
        }
        if (p.ff > 1 && dist[p.ff - 1] == -1) {
            q.push(mapa(p.ff - 1, p.ss + 1));
        }
    }

    return 0;
}