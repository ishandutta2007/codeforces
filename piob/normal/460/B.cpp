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

const int MAXN = 100010;

int s(int x){
    int r = 0;
    while(x){
        r += x % 10;
        x /= 10;
    }
    return r;
}

int pow(int a, int b){
    int r = 1;
    FWD(i,0,b) r *= a;
    return r;
}

int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    vector<int> V;
    if(a <= 1){
        FWD(x,1,2000000)
            if(x == b*pow(s(x),a)+c)
                V.push_back(x);
    }else{
        FWD(sx,1,2000000){
            if(b*pow(sx,a)+c >= 1e9) break;
            if(b*pow(sx,a)+c > 0 && s(b*pow(sx,a)+c) == sx)
                V.push_back(b*pow(sx,a)+c);
        }
    }
    printf("%d\n", (int)V.size());
    for(int v : V) printf("%d ", v);
    printf("\n");
    return 0;
}