//DS includes
#include<bitset>
#include<complex>
#include<deque>
#include<map>
#include<queue>
#include<set>
#include<stack> 
#include<vector>



//Other Includes
#include<algorithm>
#include<cassert>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<iostream>
#include<sstream>




#define oo              0xBADC0DE
#define s(n)            scanf("%d",&n)
#define sl(n)           scanf("%lld",&n)
#define sf(n)           scanf("%lf",&n)
#define fill(a,v)       memset(a, v, sizeof a)
#define ull             unsigned long long
#define ll              long long
#define bitcount        __builtin_popcount
#define all(x)          x.begin(), x.end()
#define pb( z )         push_back( z )
#define gcd             __gcd
using namespace std;
char a[1024], b[1024];

int dp[1024][1024];

int solve(int p1, int p2) {
    
    int &ret = dp[p1][p2];
    if (~ret)
        return ret;
    if (a[p1]==0) {
        if (b[p2]==0) {
            return ret=0;
        } else {
            return ret=1+solve(p1, p2+1);
        }
    }
    if (b[p2]==0) {
        return ret=1 + solve(p1+1, p2);
    }
    
    if (a[p1]==b[p2]) {
        return ret = solve(p1+1, p2+1);
    } else {
        return ret = 1 + min( solve(p1, p2+1) , min(solve(p1+1, p2+1), solve(p1+1, p2)) );
    }
}

void recon(int p1, int p2, int ins) {
    int index = p1+1 + ins;
    if (a[p1]==0) {
        if (b[p2]==0) {
            return ;
        } else {
            printf("INSERT %d %c\n", index, b[p2]);
            return recon(p1, p2+1, ins+1);
        }
    }
    
    if (b[p2]==0) {
        printf("DELETE %d\n", index);
        return recon(p1+1, p2, ins-1);
    }
    if (a[p1]==b[p2]) {
        return recon(p1+1, p2+1, ins);
    } else {
        int type = 0;
        int ret =  solve(p1, p2+1);
        int ret2 = solve(p1+1, p2+1);
        int ret3 = solve(p1+1, p2);
        if (ret2 < ret) {
            type=1;
            ret = ret2;
        }       
        if (ret3 < ret) {
            type=2;
            ret = ret3;
        }
        
        if (type==0) {
            printf("INSERT %d %c\n", index, b[p2]);
            return recon(p1, p2+1, ins+1);
        }
        if (type==1) {
            printf("REPLACE %d %c\n", index, b[p2]);
            return recon(p1+1, p2+1, ins);
        }
        if (type==2) {
            printf("DELETE %d\n", index);
            return recon(p1+1, p2, ins-1);
        }
        
    }
}


int main(){
    fill( dp, -1 );
    scanf("%s %s", a, b);
    int moves = solve(0,0);
    printf("%d\n", moves);
    recon(0,0,0);
    return 0;
}