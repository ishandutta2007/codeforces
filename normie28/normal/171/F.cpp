// Credit to robs77 for this template
/***********HEADER***************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
#include <cstdio>
#include <stdlib.h>
#include <stack>
#include <numeric>
#include <bitset>
#include <cctype>
/***********MACROS***************/
typedef long long ll;
#define MAX 1000005
using namespace std;
int n,m;
#define INF 2147483647
#define inf 1<<30
#define MOD 1000000007
#define EPS 1e-20
#define G 9.8
#define PI acos(-1)
#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
/*********VARIABLE****************/
bool debug = false;
int k;
int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};
 
 /*********FUNCTIONS**************/
 
bitset<MAX> bs;
void init() {
    for(int i=3;i*i<=MAX;i+=2) if(!bs[i]){
        for(int j=i*i; j<=MAX; j += i+i) {
            bs[j]=1;
        }
    }
}
bool isP(int x) {
    return x%2!=0 && !bs[x];
}
int rev(int x) {
    int s = 0;
    while(x>0) {
        s=s*10+x%10; x/=10;
    }
    return s;
}
/***********MAIN**************/
int main(){
    init();
    scanf("%d",&n);
    int i,ri,c;
    for(i=13,ri=rev(i),c=0;c<n;i++,ri = rev(i)) {
        if (i!=ri && isP(i) && isP(ri)) c++;
        if (c==n) break;
    }
    printf("%d\n", i);
    return 0;
}