#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 2000+5;
const int ha = 998244353;

inline int add(int x,int y){
    (x += y);if(x >= ha) x -= ha;
    return x;
}

int pw[MAXN];
int f[MAXN][MAXN];
char str[MAXN];
int sm[MAXN],n;

int main(){
    pw[0] = 1;FOR(i,1,MAXN-1) pw[i] = add(pw[i-1],pw[i-1]);
    scanf("%s",str+1);n = strlen(str+1);
    FOR(i,1,n) sm[i] = sm[i-1]+(str[i]=='?');
    FOR(len,2,n){
        FOR(l,1,n-len+1){
            int r = l+len-1;
            if(str[l] != '(') f[l][r] = add(f[l][r],f[l+1][r]);
            if(str[r] != ')') f[l][r] = add(f[l][r],f[l][r-1]);
            if(str[l] != '(' && str[r] != ')') f[l][r] = add(f[l][r],ha-f[l+1][r-1]);
            if(str[l] != ')' && str[r] != '(') f[l][r] = add(f[l][r],add(f[l+1][r-1],pw[std::max(0,sm[r-1]-sm[l])]));
        }
    }
    printf("%d\n",f[1][n]);
    return 0;
}