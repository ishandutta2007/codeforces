#include <cstdio>
#include <cstring>
#include <vector>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef pair < int, int > pii;

const int N = 1e5 + 500;
const int OFF = (1 << 17);

int nxt[N], tour[2 * OFF], lst[N], n, a[N], ans[N];
vector < int > q[N];

void update(int i,int x){
    tour[OFF + i ] = x;
    for(i = (i + OFF) / 2; i ; i /= 2)
        tour[i] = tour[2 * i] + tour[2 * i + 1];
}

int query(int i,int k){
    if(tour[i] < k) return n;
    if(i >= OFF) return i - OFF;
    if(tour[2 * i] >= k) return query(2 * i, k);
    return query(2 * i + 1, k - tour[2 * i]);
}

int main(){
    memset(lst, -1, sizeof(lst));
    memset(nxt, -1, sizeof(nxt));
    scanf("%d", &n);
    for(int i = 0;i<n;i++){
        scanf("%d", a + i);
        if(lst[a[i]] != -1)
            nxt[lst[a[i]]] = i;
        else
            update(i, 1);
        lst[a[i]] = i;
        q[0].PB(i + 1);
    }
    for(int i = 0;i<n;i++){
        for(int Q : q[i]){
            int nl = query(1, Q + 1) - 1;
            q[nl + 1].PB(Q);
            ans[Q]++;
        }
        q[i].resize(0);
        update(i, 0);
        if(nxt[i] != -1) update(nxt[i], 1);
    }
    for(int i = 1;i<=n;i++)
        printf("%d ", ans[i]);
    printf("\n");
}