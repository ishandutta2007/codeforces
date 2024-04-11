//#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#define mp make_pair
#define pb push_back

//#define MAXTEST

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, clock()*1.0/CLOCKS_PER_SEC)

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "E"

typedef long long ll;
typedef long double ld;

const int MOD = 1000000000;
const int MAXN = 210000;

struct Matrix{
    int a[3][3];

    Matrix(int type = 1){
        memset(a,0,sizeof(a));
        if (type)
        a[0][0] = a[1][1] = a[2][2] = 1;
    }
    Matrix(const Matrix& r){
        memcpy(a,r.a,sizeof(a));
    }
    Matrix(int a11,int a12,int a13,int a21,int a22,int a23,int a31,int a32,int a33){
        a[0][0] = a11; a[0][1] = a12; a[0][2] = a13;
        a[1][0] = a21; a[1][1] = a22; a[1][2] = a23;
        a[2][0] = a31; a[2][1] = a32; a[2][2] = a33;
    }
};

Matrix operator*(const Matrix& a,const Matrix& b){
    Matrix res(0);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++){
            ll temp = 0;
            for (int k = 0; k < 3; k++)
                temp += a.a[i][k]*1LL*b.a[k][j];
            res.a[i][j] = temp % MOD;
        }
    return res;
}

Matrix tree[MAXN*3];
int addv[MAXN*3];
int len[MAXN*3];
int lst;
int n;

int fib[MAXN];


void update(int x,int a){
    tree[x+lst] =  Matrix(1,1,0,
                          1,0,0,
                          a,0,1);
    x = x+lst;
    while (x > 0){
        x /= 2;
        tree[x] = tree[2*x+1]*tree[2*x];
    }
}

Matrix get(int v,int l,int r,int L,int R){
    if (R < l || r < L)
        return Matrix();
    if (L <= l && r <= R)
        return tree[v];
    return get(2*v+1,(l+r)/2+1,r,L,R)*get(2*v,l,(l+r)/2,L,R);
}

int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif
    lst = 2;
    int m;
    #ifdef MAXTEST
       n = m = 200000;
    #else
    scanf("%d %d",&n,&m);
    #endif
    while (lst < n) lst *= 2;
    for (int i = 0; i < n; i++){
        int a;
        #ifdef MAXTEST
         a = rand();
        #else
        scanf("%d",&a);
        #endif
        tree[lst+i] = Matrix(1,1,0,
                             1,0,0,
                             a,0,1);
        len[lst+i] = 1;
    }

    for (int i = lst - 1; i > 0; i--){
        tree[i] = tree[2*i+1]*tree[2*i];
        len[i] = len[2*i]+len[2*i+1];
    }

    for (int i = 0; i < 2*lst; i++)
        addv[i] = 0;

    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i < MAXN; i++)
        fib[i] = (fib[i-1] + fib[i-2]) % MOD;
        
    for (int i = 0; i < m; i++){
        int ty;
        #ifdef MAXTEST
         ty = 2;
        #else   
        scanf("%d",&ty);
        #endif
        if (ty == 1){
            int x,a;
            scanf("%d %d",&x,&a);
            --x;
            update(x,a);
        } else if (ty == 2){
            int l,r;
            #ifdef MAXTEST
              l = rand();
              r = rand();
              if (l > r) swap(l,r);
            #else  
              scanf("%d %d",&l,&r);
            #endif
            --l,--r;
            Matrix res = get(1,0,lst-1,l,r);

            printf("%d\n",res.a[2][0]);
        } 
    }
      
    TIMESTAMP(end);
    return 0;
}