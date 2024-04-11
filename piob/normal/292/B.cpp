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
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)
#define PII pair<int, int>
#define x first
#define y second

using namespace std;

typedef long long LL;

int n, m;
vector<int> E[100010];

bool bus(){
    int c = 0;
    FWD(i,1,n+1)
        if(E[i].size() == 1)
            ++c;
        else if(E[i].size() != 2)
            return 0;
    return c == 2;
}

bool ring(){
    FWD(i,1,n+1)
        if(E[i].size() != 2)
            return 0;
    return 1;
}

bool star(){
    int c = 0;
    FWD(i,1,n+1)
        if(E[i].size() != 1)
            ++c;
    return c == 1;
}

int main(){
    scanf("%d %d", &n, &m);
    int a, b;
    FWD(i,0,m){
        scanf("%d %d", &a, &b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    if(bus())
        printf("bus topology\n");
    else if(ring())
        printf("ring topology\n");
    else if(star())
        printf("star topology\n");
    else
        printf("unknown topology\n");   
    return 0;
}