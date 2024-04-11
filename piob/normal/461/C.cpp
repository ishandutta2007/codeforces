#include <bits/stdc++.h>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second
#define pb push_back
#define re real()
#define im imag()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef double K;
typedef vector<int> VI;

int dx[] = {0,0,-1,1}; //1,1,-1,1};
int dy[] = {-1,1,0,0}; //1,-1,1,-1};

int n, d, m, p, q, w;
int D[300030];
bool rev;

void dadd(int x, int y){
    x += d;
    while(x){
        D[x] += y;
        x /= 2;
    }
}

int dget(int x, int y){
    int r = 0;
    x += d;
    y += d;
    while(x < y){
        if(x&1){
            r += D[x];
            ++x;
        }
        if((y&1)==0){
            r += D[y];
            --y;
        }
        x /= 2;
        y /= 2;
    }
    if(x == y) r += D[x];
    return r;
}

int main(){
    scanf("%d", &n);
    d = 1;
    while(d < n) d *= 2;
    FWD(i,0,n) dadd(i, 1);
    p = 0;
    q = n+1;
    scanf("%d", &m);
    FWD(r,0,m){
        int t;
        scanf("%d", &t);
        w = q-p-1;
        if(t == 1){
            int a;
            scanf("%d", &a);
            if(rev){
                a = w-a;
            }
            //printf("real place: %d\n", a);
            if(a < w-a){
                //printf("left to right\n");
                if(rev) rev = 0;

                FWD(i,0,a){
                    int c = dget(p+i, p+i);
                    dadd(p+i, -c);
                    dadd(p+2*a-i-1, c);
                }
                p += a;
            }else{
                //printf("right to left\n");
                if(!rev) rev = 1;
                FWD(i,0,w-a){
                    int c = dget(p+a+i,p+a+i);
                    dadd(p+a+i, -c);
                    dadd(p+a-i-1, c);
                }
                q -= w-a;
            }
            //FWD(i,0,n) printf("%d ", dget(i,i));
            //printf("\n");
        }else{
            int a, b;
            scanf("%d %d", &a, &b);
            if(rev){
                a = w-a;
                b = w-b;
                swap(a, b);
            }
            //printf("r: %d p: %d\n", (int)rev, p);
            //printf("z: %d %d\n", p+a, p+b-1);
            printf("%d\n", dget(p+a,p+b-1));
        }
    }
    return 0;
}