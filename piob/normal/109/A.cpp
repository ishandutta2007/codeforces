#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)
#define PACKS(a) int a; scanf("%d", &a); ++a; while(--a)
#define PII pair<int, int>
#define x first
#define y second

using namespace std;

bool check(int S, int P){
    if((S - 4*P)%3)
        return 0;
    int y = (S-4*P)/3;
    if(y < 0)
        return 0;
    if((S-7*y)%4)
        return 0;
    int x = (S-7*y)/4;
    if(x < 0)
        return 0;
    FWD(i,0,x)
        printf("4");
    FWD(i,0,y)
        printf("7");
    printf("\n");
    return 1;
}

int main(){
    int S;
    scanf("%d", &S);
    FWD(i,1,S)
        if(check(S, i))
            return 0;
    printf("-1\n");
    return 0;
}