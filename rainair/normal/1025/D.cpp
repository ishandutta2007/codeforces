#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define se second
#define U unsigned
#define P std::pair
#define Re register
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1000+5;
int f[MAXN][MAXN],L[MAXN][MAXN],R[MAXN][MAXN];
int a[MAXN],n;

inline int gcd(int x,int y){
    return !y ? x : gcd(y,x%y);
}

int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i),L[i][i] = R[i][i] = 1;
    FOR(i,1,n) FOR(j,1,n) if(gcd(a[i],a[j]) != 1) f[i][j] = 1;
    ROF(l,n,1){
        FOR(r,l,n){
            FOR(k,l,r){
                if(L[l][k] && R[k][r]){
                    if(l == 1 && r == n){
                        puts("Yes");return 0;
                    }
                    if(f[l-1][k]) R[l-1][r] = 1;
                    if(f[k][r+1]) L[l][r+1] = 1; 
                }
            }
        }
    }
    puts("No");
    return 0;
}