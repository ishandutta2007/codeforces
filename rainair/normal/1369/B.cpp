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

const int MAXN = 2e5 + 5;
char str[MAXN];
int n;

int main(){
    int T;scanf("%d",&T);
    while(T--){int n;scanf("%d",&n);
        scanf("%s",str+1);
        int ps1 = 1;str[0] = str[n+1] = '#';
        while(str[ps1] == '0') ps1++;
        int ps2 = n;
        while(str[ps2] == '1') ps2--;
        ps1--;ps2++;
        if(ps1) FOR(i,1,ps1) putchar('0');
        if(ps1+1 != ps2) putchar('0');
        ps2 = n-ps2+1;
        FOR(i,1,ps2) putchar('1');puts("");
    }
    return 0;
}