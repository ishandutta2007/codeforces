/*
 * Author: RainAir
 * Time: 2020-03-01 23:05:54
 */
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
#define U unsigned
#define P std::pair
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 2e5  + 5;
const int ha = 1e9 + 9;
char str[MAXN];
int n;
int sm[MAXN];
std::vector<int> ps;
int hsh[2][MAXN],pw[MAXN];
inline int calc(int o,int l,int r){
    return (hsh[o][r]+ha-1ll*hsh[o][l-1]*pw[r-l+1]%ha)%ha;
}

int main(){
    scanf("%d",&n);
    scanf("%s",str+1);
    FOR(i,1,n) if(str[i] == '0') ps.pb(i);
    FOR(i,1,n) sm[i] = sm[i-1]+(str[i]=='0');
    pw[0] = 1;FOR(i,1,n) pw[i] = 2ll*pw[i-1]%ha;
    FOR(i,1,(int)ps.size()){
        hsh[0][i] = (2ll*hsh[0][i-1]%ha+(ps[i-1]&1))%ha;
        hsh[1][i] = (2ll*hsh[1][i-1]%ha+(!(ps[i-1]&1)))%ha;
    }
    int q;scanf("%d",&q);
    while(q--){
        int l1,l2,len;scanf("%d%d%d",&l1,&l2,&len);
        bool fg1 = l1&1,fg2 = l2&1;
        int r1 = l1+len-1,r2 = l2+len-1;
        if(sm[r1]-sm[l1-1] != sm[r2]-sm[l2-1]){
            puts("No");continue;
        }
        r1 = std::upper_bound(all(ps),r1)-ps.begin();
        r2 = std::upper_bound(all(ps),r2)-ps.begin();
        l1 = std::lower_bound(all(ps),l1)-ps.begin()+1;
        l2 = std::lower_bound(all(ps),l2)-ps.begin()+1;
        if(l1 > r1 && l2 > r2){
            puts("Yes");
            continue;
        }
//        DEBUG(calc(fg1,l1,r1));DEBUG(calc(fg2,l2,r2));
        puts(calc(fg1,l1,r1)==calc(fg2,l2,r2) ? "Yes" : "No");
    }
    return 0;
}