#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iostream>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)
#define PII pair<int, int>
#define PLL pair<long long, long long>
#define x first
#define y second

using namespace std;

typedef long long LL;

LL sn;
LL n;
vector<PLL> D;
LL z;
int r;
vector<PII> S;

//(a+b)(a+c)(b+c) = n/3

void cnt(int k, LL x, LL y){
    if(k == D.size()){
        z = n/x/y;
        if(
            (x+y-z)%2 == 0 && (x+y-z) > 0 &&
            (y+z-x)%2 == 0 && (y+z-x) > 0 &&
            (z+x-y)%2 == 0 && (z+x-y) > 0
        ){
            ++r;
        }
    }else{
        FWD(i,0,D[k].y+1){
            LL sy = y;
            FWD(j,0,D[k].y+1-i){
                cnt(k+1, x, y);
                y *= D[k].x;
            }
            y = sy;
            x *= D[k].x;
        }
    }
}

int main(){
    cin >> n;
    if(n % 3){
        printf("0\n");
        return 0;
    }
    n /= 3;
    sn = n;
    for(LL i = 2; i*i <= n; ++i)
        if(n%i == 0){
            D.push_back(PLL(i,0));
            while(n%i == 0){
                n /= i;
                ++D.back().y;
            }
        }
    if(n > 1){
        D.push_back(PLL(n, 1));
    }
    n = sn;
    cnt(0, 1, 1);
    printf("%d\n", r);
    return 0;
}