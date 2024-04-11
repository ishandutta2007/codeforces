#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
const int P = 1 << 19;
const int mod = 1e9 + 7;
int n;
vector < int > v[N];
int aa , bb;
long long dist[P];
bool done[N];
int subtree[N];
void dfs1(int node , int parent){
    subtree[node] = 1;
    for(int next : v[node]){
        if(next != parent && !done[next]){
            dfs1(next , node);
            subtree[node] += subtree[next];
        }
    }
}
int find(int node , int parent , int sz){
    for(int next : v[node]){
        if(next != parent && !done[next] && subtree[next] > sz){
            return find(next , node , sz);
        }
    }
    return node;
}
int sum[N];
int cur;
int arr[N];
int sz;
void dfs2(int node , int parent , int depth){
    if(depth == sz){
        arr[depth] = 1;
        ++sz;
    }
    else{
        ++arr[depth];
    }
    if(depth == cur){
        sum[depth] = 1;
        ++cur;
    }
    else{
        ++sum[depth];
    }
    for(int next : v[node]){
        if(next != parent && !done[next]){
            dfs2(next , node , depth + 1);
        }
    }
}
const double pi = acos(-1.0);
int rev[P];
void pre(int k , int n){
    int res;
    for(int i = 0 ; i < n ; ++i){
        res = 0;
        for(int j = 0 ; j < k ; ++j){
            if((i >> j) & 1){
                res |= 1 << (k - j - 1);
            }
        }
        rev[i] = res;
    }
}
struct base{
    double x , y;
    base(){
        x = 0;
        y = 0;
    }
    base(double _x , double _y){
        x = _x;
        y = _y;
    }
    inline base operator + (const base &o) const {
        return base(x + o.x , y + o.y);
    }
    inline base operator - (const base &o) const {
        return base(x - o.x , y - o.y);
    }
    inline base operator * (const base &o) const {
        return base(x * o.x - y * o.y , x * o.y + y * o.x);
    }
};
base a[P];
base c[P];
void fft(base a[] , int n , bool inv){
    for(int i = 0 ; i < n ; ++i){
        if(rev[i] > i){
            swap(a[i] , a[rev[i]]);
        }
    }
    for(int size = 2 ; size <= n ; size <<= 1){
        int m = size >> 1;
        base w(cos(2 * pi / size) , sin(2 * pi / size) * (inv ? -1 : 1));
        for(int i = 0 ; i < n ; i += size){
            base cur(1 , 0);
            for(int j = 0 ; j < m ; ++j){
                base v = a[i + j];
                base u = a[i + j + m] * cur;
                a[i + j] = v + u;
                a[i + j + m] = v - u;
                cur = cur * w;
            }
        }
    }
}
void square(int arr[] , int n , int sign){
    if(n <= 16){
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < n ; ++j){
                dist[i + j] += 1LL * sign * arr[i] * arr[j];
            }
        }
        return;
    }
    int k = 1;
    while((1 << k) < n + n){
        ++k;
    }
    for(int i = 0 ; i < n ; ++i){
        a[i] = base(arr[i] , 0);
    }
    for(int i = n ; i < (1 << k) ; ++i){
        a[i] = base();
    }
    n = 1 << k;
    pre(k , n);
    fft(a , n , 0);
    for(int i = 0 ; i < n ; ++i){
        c[i] = a[i] * a[i];
    }
    fft(c , n , 1);
    for(int i = 0 ; i < n ; ++i){
        dist[i] += sign * ((long long)(c[i].x / n + 0.5));
    }
}
void get(int node){
    sum[0] = 1;
    cur = 1;
    for(int next : v[node]){
        if(!done[next]){
            sz = 1;
            arr[0] = 0;
            dfs2(next , node , 1);
            square(arr , sz , -1);
        }
    }
    square(sum , cur , 1);
}
void solve(int node){
    dfs1(node , 0);
    int cent = find(node , 0 , subtree[node] >> 1);
    get(cent);
    done[cent] = 1;
    for(int next : v[cent]){
        if(!done[next]){
            solve(next);
        }

    }
}
int k;
int main(){
    scanf("%d %d" , &n , &k);
    for(int i = 1 ; i < n ; ++i){
        scanf("%d %d" , &aa , &bb);
        v[aa].emplace_back(bb);
        v[bb].emplace_back(aa);
    }
    solve(1);
    long long ans = 0;
    for(int i = 1 ; i < n ; ++i){
        ans += ((i + k - 1LL) / k) * dist[i];
    }
    printf("%lld\n" , ans >> 1);
}