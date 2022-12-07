#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <functional>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)

using namespace std;

int n, a, z, r;
vector<int> pos, neg;

int main(){
    scanf("%d", &n);
    z = 0;
    FWD(i,0,n){
        scanf("%d", &a);
        if(a > 0) pos.push_back(a);
        if(a < 0) neg.push_back(a);
        if(a == 0) ++z;
    }
    r = n - 2;
    printf("1 %d\n", neg.back());
    neg.pop_back();
    if(pos.size()){
        printf("1 %d\n", pos.back());
        pos.pop_back();
    }else{
        printf("2 %d %d\n", neg.back(), neg[neg.size()-2]);
        neg.pop_back();
        neg.pop_back();
        --r;
    }
    printf("%d", r);
    FWD(i,0,pos.size())
        printf(" %d", pos[i]);
    FWD(i,0,neg.size())
        printf(" %d", neg[i]);
    FWD(i,0,z)
        printf(" 0");
    printf("\n");
    return 0;
}