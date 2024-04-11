#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb emplace_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

std::string str;
const int B = 50;
int f[2][55][20*B+3][10*B+3];

inline int dp(int o,int n,int num,int r){
    // 0-> -1
    // 1->1
    if(n == SZ(str)) return r ? 1e9 : 0;
    if(num+10*B > 20*B || num+10*B < 0 || r+5*B > 10*B || r+5*B < 0){
        return 1e9;
    }
    int &res = f[o][n][num+10*B][r+5*B];
    if(res != -1) return res;
    res = std::min({dp(o,n,num+(o==1?1:-1),r)+SZ(str)-n,dp(o,n+1,num,r*10+str[n]-'0'-num),dp(!o,n+1,num,r*10+str[n]-'0'-num)});
    return res;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin >> str;
    str = "000"+str;CLR(f,-1);
    printf("%d\n",std::min(dp(1,0,0,0),dp(0,0,0,0)));
    return 0;
}