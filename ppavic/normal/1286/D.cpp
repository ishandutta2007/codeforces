#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int , int > pii;
typedef vector < int > vi;
typedef set < int > si;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
const int OFF = (1 << 17);

inline int add(int A,int B){
    if(A + B >= MOD) return A + B - MOD;
    return A + B;
}

inline int sub(int A,int B){
    if(A - B < 0) return A - B + MOD;
    return A - B;
}

inline int mul(int A,int B){
    return (ll)A * B % MOD;
}

inline int pot(int A,int B){
    int sol = 1, bs = A;
    for(; B ; B /= 2){
        if(B&1) sol = mul(sol, bs);
        bs = mul(bs, bs);
    }
    return sol;
}

inline int divv(int A,int B){
    return mul(A, pot(B, MOD - 2));
}

int V[OFF][2][2], n ;
int p[N], x[N], v[N];

struct node{
    int P[2][2];
    int l,  r;
    node(){ P[0][0] = 0, P[0][1] = 0, P[1][0] = 0, P[1][1] = 0;}
};

node tour[2 * OFF];
vector < pair < int , pii > > vec;
vector < pair < pair < double, pii > , pii > > event;

node mrg(node A, node B){
    node C;
    C.l = A.l, C.r = B.r;
    for(int i = 0;i < 2;i++){
        for(int j = 0;j < 2;j++){
            for(int k = 0;k < 2;k++){
                for(int k2 = 0;k2 < 2;k2++){
                    C.P[i][j] = add(C.P[i][j], mul(mul(A.P[i][k], B.P[k2][j]), V[A.r][k][k2]));
                }
            }
        }
    }
    return C;
}

void update(int i,int k,int k2){
    V[i][k][k2] = 0;
    for(i = (i + OFF) / 2; i ; i /= 2)
        tour[i] = mrg(tour[2 * i], tour[2 * i + 1]);
}

int get_prob(){
    int sm = 0;
    for(int j = 0;j < 4;j++)
        sm = add(sm, tour[1].P[j % 2][j / 2]);
    return sm;
}

int main(){
    scanf("%d", &n);
    for(int i = 0;i < OFF;i++){
        V[i][0][0] = 1;
        V[i][0][1] = 1;
        V[i][1][0] = 1;
        V[i][1][1] = 1;
    }
    for(int i = 0;i < n;i++){
        int x, v, p;
        scanf("%d%d%d", &x, &v, &p);
        vec.PB({x, {v, p}});
    }
    sort(vec.begin(), vec.end());
    for(int i = 0;i < n;i++){
        x[i] = vec[i].X;
        v[i] = vec[i].Y.X;
        p[i] = vec[i].Y.Y;
    }
    for(int i = 0;i < OFF;i++)
        tour[i + OFF].P[0][0] = 1, tour[i + OFF].l = i, tour[i + OFF].r = i;
    for(int i = 0;i < n;i++){
        tour[i + OFF].P[0][0] = divv(100 - vec[i].Y.Y, 100);             // left
        tour[i + OFF].P[1][1] = divv(vec[i].Y.Y, 100);       // right
        //printf("%d %d\n", tour[i + OFF].P[0][0], tour[i + OFF].P[1][1]);
    }
    for(int i = OFF - 1;i >= 1;i--)
        tour[i] = mrg(tour[2 * i], tour[2 * i + 1]);
    for(int i = 0;i + 1 < n;i++){
        event.PB({{double(x[i + 1] - x[i]) / (double)(v[i + 1] + v[i]), {divv(x[i + 1] - x[i], v[i + 1] + v[i]), i}}, {1, 0}});
        if(v[i + 1] > v[i])
            event.PB({{double(x[i + 1] - x[i]) / (double)(v[i + 1] - v[i]), {divv(x[i + 1] - x[i], v[i + 1] - v[i]), i}}, {0, 0}});
        if(v[i] > v[i + 1])
            event.PB({{double(x[i + 1] - x[i]) / (double)(v[i] - v[i + 1]), {divv(x[i + 1] - x[i], v[i] - v[i + 1]), i}}, {1, 1}});
    }
    sort(event.begin(), event.end());
    int fin = 0;
    //printf("TOUR %d, %d | 00: %d | 01: %d | 10: %d | 11: %d | \n", tour[1].l, tour[1].r, tour[1].P[0][0], tour[1].P[0][1], tour[1].P[1][0], tour[1].P[1][1]);
    for(int i = 0;i < (int)event.size();i++){
        int st = get_prob();
        pair < pair < double, pii > , pii > cur = event[i];
       // printf("event u %lf , protoni %d i %d, smjer %d i %d, prob %d\n", cur.X.X, cur.X.Y.Y, cur.X.Y.Y + 1, cur.Y.X, cur.Y.Y, st);
        update(cur.X.Y.Y, cur.Y.X, cur.Y.Y);
        //printf("novi st %d\n", get_prob());
        st = sub(st, get_prob());
        fin = add(fin, mul(st, cur.X.Y.X));
    }
    printf("%d\n", fin);
    return 0;
}