#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int M = 3e5 + 5;
const int LN = 19;
struct edge{
    int a , b;
    int len;
    int idx;
    bool operator < (const edge &b) const {
        return make_pair(len , idx) < make_pair(b.len , b.idx);
    }
};
int n , m;
edge arr[M];
int comp[M];
int preparent[N];
int presizes[N];
int prefind(int node){
    if(preparent[node] == node){
        return node;
    }
    return preparent[node] = prefind(preparent[node]);
}
int presolve(){
    for(int i = 1 ; i <= n ; ++i){
        preparent[i] = i;
        presizes[i] = 1;
    }
    int oddcnt = n;
    for(int i = 1 ; i <= m ; ++i){
        int x = prefind(arr[i].a);
        int y = prefind(arr[i].b);
        if(x != y){
            oddcnt -= (presizes[x] & 1);
            oddcnt -= (presizes[y] & 1);
            presizes[x] += presizes[y];
            preparent[y] = x;
            oddcnt += (presizes[x] & 1);
        }
        if(!oddcnt){
            return i;
        }
    }
    return m + 1;
}
int ans[M];
int parent[N];
int sizes[N];
int oddcnt;
pair < int , int > rollback[M * LN];
int cur;
inline int find(int node){
    while(parent[node] != node){
        node = parent[node];
    }
    return node;
}
bool join(int a , int b){
    int x = find(a);
    int y = find(b);
    if(x == y){
        return 0;
    }
    oddcnt -= sizes[x] & 1;
    oddcnt -= sizes[y] & 1;
    if(sizes[x] < sizes[y]){
        swap(x , y);
    }
    rollback[++cur] = make_pair(y , x);
    sizes[x] += sizes[y];
    parent[y] = x;
    oddcnt += sizes[x] & 1;
    return 1;
}
void solve(int l , int r , int ql , int qr){
    if(r < l){
        return;
    }
    int before = cur;
    int mid = l + r >> 1;
    int res;
    for(int i = l ; i <= mid ; ++i){
        if(comp[i] < ql){
            if(join(arr[comp[i]].a , arr[comp[i]].b)){
                if(!oddcnt){
                    res = comp[i];
                    break;
                }
            }
        }
    }
    for(int i = ql ; i <= qr ; ++i){
        if(arr[i].idx <= mid){
            if(join(arr[i].a , arr[i].b)){
                if(!oddcnt){
                    res = i;
                    break;
                }
            }
        }
    }
    ans[mid] = arr[res].len;
    while(cur > before){
        auto data = rollback[cur--];
        oddcnt -= sizes[data.second] & 1;
        parent[data.first] = data.first;
        sizes[data.second] -= sizes[data.first];
        oddcnt += sizes[data.first] & 1;
        oddcnt += sizes[data.second] & 1;
    }
    for(int i = ql ; i < res ; ++i){
        if(arr[i].idx < l){
            join(arr[i].a , arr[i].b);
        }
    }
    solve(l , mid - 1 , res , qr);
    while(cur > before){
        auto data = rollback[cur--];
        oddcnt -= sizes[data.second] & 1;
        parent[data.first] = data.first;
        sizes[data.second] -= sizes[data.first];
        oddcnt += sizes[data.first] & 1;
        oddcnt += sizes[data.second] & 1;
    }
    for(int i = l ; i <= mid ; ++i){
        if(comp[i] < ql){
            join(arr[comp[i]].a , arr[comp[i]].b);
        }
    }
    solve(mid + 1 , r , ql , res);
    while(cur > before){
        auto data = rollback[cur--];
        oddcnt -= sizes[data.second] & 1;
        parent[data.first] = data.first;
        sizes[data.second] -= sizes[data.first];
        oddcnt += sizes[data.first] & 1;
        oddcnt += sizes[data.second] & 1;
    }
}
int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d %d %d" , &arr[i].a , &arr[i].b , &arr[i].len);
        arr[i].idx = i;
    }
    int start = presolve();
    sort(arr + 1 , arr + 1 + m);
    for(int i = 1 ; i <= m ; ++i){
        comp[arr[i].idx] = i;
    }
    for(int i = 1 ; i < start ; ++i){
        ans[i] = -1;
    }
    for(int i = 1 ; i <= n ; ++i){
        parent[i] = i;
        sizes[i] = 1;
    }
    cur = 0;
    oddcnt = n;
    solve(start , m , 1 , m);
    for(int i = 1 ; i <= m ; ++i){
        printf("%d\n" , ans[i]);
    }
}