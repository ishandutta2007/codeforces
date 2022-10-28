#include "bits/stdc++.h"
using namespace std;
const int N = 55;
const int M = 105;
const int T = 2e4 + 4;
const int P = 1 << 15;
int n , m , t , x;
int a[M] , b[M] , c[M];
int p[M][T];
int pre[M][T];
double dpnode[N][T];
double dpedge[M][T];
int graph[N][N];
void spfa(){
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            graph[i][j] = 1e9 + 9;
        }
        graph[i][i] = 0;
    }
    for(int i = 1 ; i <= m ; ++i){
        graph[a[i]][b[i]] = min(graph[a[i]][b[i]] , c[i]);
    }
    for(int k = 1 ; k <= n ; ++k){
        for(int i = 1 ; i <= n ; ++i){
            for(int j = 1 ; j <= n ; ++j){
                graph[i][j] = min(graph[i][j] , graph[i][k] + graph[k][j]);
            }
        }
    }
}
const double pi = acos(-1.0);
int rev[P];
void bit(int k , int n){
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
    base(double _x){
        x = _x;
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
base lft[P];
base rgt[P];
base res[P];
void mult(int n , int k){
    for(int i = n ; i < n + n ; ++i){
        lft[i] = base();
        rgt[i] = base();
    }
    ++k;
    n += n;
    bit(k , n);
    fft(lft , n , 0);
    fft(rgt , n , 0);
    for(int i = 0 ; i < n ; ++i){
        res[i] = lft[i] * rgt[i];
    }
    fft(res , n , 1);
    for(int i = 0 ; i < n ; ++i){
        res[i].x /= n;
    }
}
void mult(int edge , int pl , int pr , int dl , int dr , int n , int k){
    int node = b[edge];
    if(n <= 16){
        for(int i = pl ; i <= pr ; ++i){
            for(int j = dl ; j <= dr ; ++j){
                dpedge[edge][i + j] += p[edge][i] * dpnode[node][j];
            }
        }
    }
    else{
        for(int i = 0 ; i < n ; ++i){
            lft[i] = base(p[edge][pl + i]);
            rgt[i] = base(dpnode[node][dl + i]);
        }
        mult(n , k);
        for(int i = 0 ; i < n + n && pl + dl + i <= t ; ++i){
            dpedge[edge][pl + dl + i] += res[i].x;
        }
    }
}
void insert(int edge , int cur){
    mult(edge , 1 , 1 , cur , cur , 1 , 0);
    mult(edge , 2 , 2 , cur , cur , 1 , 0);
    int mx = cur & -cur;
    int lg = 0;
    for(int size = 2 ; size <= mx ; size <<= 1){
        int pstart = size + 1;
        int pfinish = size << 1;
        int cstart = cur - size;
        int cfinish = cur - 1;
        ++lg;
        mult(edge , pstart , pfinish , cstart , cfinish , size , lg);
    }
}
int main(){
    scanf("%d %d %d %d" , &n , &m , &t , &x);
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d %d %d" , a + i , b + i , c + i);
        for(int j = 1 ; j <= t ; ++j){
            scanf("%d" , &p[i][j]);
            pre[i][j] = pre[i][j - 1] + p[i][j];
        }
    }
    spfa();
    for(int i = 1 ; i < n ; ++i){
        dpnode[i][0] = graph[i][n] + x;
    }
    dpnode[n][0] = 0;
    for(int i = 1 ; i <= m ; ++i){
        insert(i , 0);
    }
    for(int i = 1 ; i <= t ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            dpnode[j][i] = 1e15 + 15;
        }
        dpnode[n][i] = 0;
        for(int j = 1 ; j <= m ; ++j){
            dpedge[j][i] += 1LL * (pre[j][t] - pre[j][i]) * (graph[b[j]][n] + x);
            dpedge[j][i] /= 1e5;
            dpedge[j][i] += c[j];
            dpnode[a[j]][i] = min(dpnode[a[j]][i] , dpedge[j][i]);
        }
        for(int j = 1 ; j <= m ; ++j){
            insert(j , i);
        }
    }
    printf("%.9lf\n" , dpnode[1][t]);
}