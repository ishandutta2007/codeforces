#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define Re register
#define LL long long
#define U unsigned
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
#define SROF(i,a,b,c) for(Re int i = a;i >= b;i-=c)
#define CLR(i,a) memset(i,a,sizeof(i))
#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define int LL
int calcw(int x,int y){
    return std::ceil((double)(x*y)/(double)2);
}

int calcb(int x,int y){
    return (x*y)/2;
}

int calcww(int x1,int y1,int x2,int y2){
    return calcw(x2,y2)-calcw(x2,y1-1)-calcw(x1-1,y2)+calcw(x1-1,y1-1);
}

int calcbb(int x1,int y1,int x2,int y2){
    return calcb(x2,y2)-calcb(x2,y1-1)-calcb(x1-1,y2)+calcb(x1-1,y1-1);
}

LL getb(int x1,int y1,int x2,int y2){
    bool opt = (x1+y1)&1;
    int n = x2-x1+1,m = y2-y1+1;
    if(opt) return n*(m/2)+((m&1) ? (n/2) + (n&1) : 0);
    else return n*(m/2)+((m&1)?(n/2):0);
}

LL getw(int x1,int y1,int x2,int y2){
    return (x2-x1+1)*(y2-y1+1)-getb(x1,y1,x2,y2);
}

signed main(){
    int T;scanf("%I64d",&T);
    //DEBUG(calcww(1,1,2,2));//DEBUG(calcw(2,0));DEBUG(calcw(0,2));DEBUG(calcw(1,0));DEBUG(calcw(0,0));
    while(T--){
        int N,M;scanf("%I64d%I64d",&N,&M);
        int w,b;
        //w = (N*M+1)/2;b = (N*M)/2;//DEBUG(w);DEBUG(b);
        w = getw(1,1,N,M);b = getb(1,1,N,M);
        int x1,y1,x2,y2;scanf("%I64d%I64d%I64d%I64d",&x1,&y1,&x2,&y2);
        //DEBUG(calcww(x1,y1,x2,y2));DEBUG(calcbb(x1,y1,x2,y2));
        //w += calcbb(x1,y1,x2,y2);b -= calcbb(x1,y1,x2,y2);
        w += getb(x1,y1,x2,y2);b -= getb(x1,y1,x2,y2);
        int xx1,yy1,xx2,yy2;
        scanf("%I64d%I64d%I64d%I64d",&xx1,&yy1,&xx2,&yy2);
        int m1 = std::max(std::min(x1,x2),std::min(xx1,xx2));
        int n1 = std::max(std::min(y1,y2),std::min(yy1,yy2));
        int m2 = std::min(std::max(x1,x2),std::max(xx1,xx2));
        int n2 = std::min(std::max(y1,y2),std::max(yy1,yy2));
        // DEBUG(m1);DEBUG(n1);DEBUG(m2);DEBUG(n2);
        if(m1 > m2 || n1 > n2){
            b += getw(xx1,yy1,xx2,yy2);w -= getw(xx1,yy1,xx2,yy2);
        }
        else{
            b += getw(xx1,yy1,xx2,yy2) + getb(m1,n1,m2,n2);
            w -= getw(xx1,yy1,xx2,yy2) + getb(m1,n1,m2,n2);

        }
        printf("%I64d %I64d\n",w,b);
    }
    return 0;
}
/*
1
2 2
1 1 2 2
1 1 2 2
*/