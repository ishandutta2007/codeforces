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

int n, k;
vector<unsigned> IPs;
char buff[24];

unsigned readIP(){
    unsigned a, b, c, d;
    scanf("%u.%u.%u.%u", &a,&b,&c,&d);
    return (a << 24) + (b << 16) + (c << 8) + d;
}

void printIP(unsigned ip){
    printf("%d.%d.%d.%d\n", ip >> 24, (ip << 8) >> 24, (ip << 16) >> 24, (ip << 24) >> 24);
}

bool check(unsigned mask){
    set<unsigned> S;
    FE(ip,IPs)
        S.insert((*ip)&mask);
    return S.size() == k;
}

void solve(){
    FWD(i,1,32){
        unsigned ip = ((1 << i) - 1) << (32 - i);
        if(check(ip)){
            printIP(ip);
            return;
        }
    }
    printf("-1\n");
}

int main(){
    scanf("%d %d", &n, &k);
    FWD(i,0,n) IPs.push_back(readIP());
    solve();
    return 0;
}