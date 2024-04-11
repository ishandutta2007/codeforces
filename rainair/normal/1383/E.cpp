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

const int MAXN = 1e6 + 5;
const int ha = 1e9 + 7;
char str[MAXN];
int a[MAXN],n;
int nxt1[MAXN];
int nxt0[MAXN];
int l0[MAXN];
int t[MAXN],f[MAXN];

int main(){
    scanf("%s",str+1);n = strlen(str+1);
    FOR(i,1,n) a[i] = str[i]-'0';
    int st = -1;
    FOR(i,1,n) if(a[i]) {st = i;break;}
    if(st == -1){
        printf("%d\n",n);
        return 0;
    }
    int las = n+1;
    ROF(i,n,0){
        nxt1[i] = las;
        if(a[i]) las = i;
    }
    FOR(i,1,n){
        if(a[i] == 1) l0[i] = 0;
        else l0[i] = l0[i-1]+1;
    }
    FOR(i,0,n) t[i] = n+1;
    ROF(i,n,0){
        nxt0[i] = t[l0[i]+1];
        t[l0[i]] = i;
    }
//    FOR(i,1,n) DEBUG(nxt0[i]);
    f[st] = st;
    FOR(i,st,n-1){
        (f[nxt0[i]] += f[i]) %= ha;
        (f[nxt1[i]] += f[i]) %= ha;
    }
    int ans = 0;
    FOR(i,1,n){
        if(l0[i] <= l0[n]) (ans += f[i]) %= ha;
    }
    printf("%d\n",ans);
    return 0;
}