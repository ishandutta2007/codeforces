#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define R register
#define LL long long
#define U unsigned
#define FOR(i,a,b) for(R int i = a;i <= b;++i)
#define RFOR(i,a,b) for(R int i = a;i >= b;--i)
#define CLR(i,a) memset(i,a,sizeof(i))
#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 10 + 5;

struct Line{
    int x,y;

    bool operator < (const Line &other) const {
        if(x == other.x) return y < other.y;
        return x < other.x;
    }
}l[MAXN];

int main(){
    FOR(i,1,8) scanf("%d%d",&l[i].x,&l[i].y);
    std::sort(l + 1,l + 8 + 1);
    if(l[1].x == l[2].x && l[2].x == l[3].x && l[4].x == l[5].x && l[6].x == l[7].x && l[7].x == l[8].x && l[1].y < l[2].y && l[2].y < l[3].y && l[4].y == l[1].y && l[5].y == l[3].y && l[6].y == l[1].y && l[7].y == l[2].y && l[8].y == l[3].y)
        puts("respectable");
    else puts("ugly");
    return 0;
}