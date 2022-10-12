#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

#define fi first
#define se second
#define mp make_pair

typedef pair <int, int> pii;

int n, m;
pii note[100002];

int main() {
    scanf("%d %d", &n, &m);
    for (int i=1; i<=m; i++) scanf("%d %d", &note[i].fi, &note[i].se);
    
    int maks = max(note[1].fi - 1 + note[1].se, n - note[m].fi + note[m].se);
    for (int i=1; i<m; i++) {
        int lr = abs(note[i+1].fi - note[i].fi);
        int ab = abs(note[i+1].se - note[i].se);
        
        lr -= ab;
        if (lr < 0) {
            puts("IMPOSSIBLE");
            return 0;
        }
        
        maks = max(maks, max(note[i].se, note[i+1].se) + lr / 2);
    }
    
    printf("%d\n", maks);
    return 0;
}