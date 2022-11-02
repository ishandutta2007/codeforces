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

const int MAXN = 1e5 + 5;
int n;char str[MAXN];
int a[MAXN];

int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        scanf("%s",str+1);
        FOR(i,1,n) a[i] = str[i]-'0';
        if(n&1){
            bool flag = 0;
            for(int i = 1;i <= n;i += 2){
                flag |= (a[i]%2 == 1);
            }
            puts(flag?"1":"2");
        }
        else{
            bool flag = 0;
            for(int i = 2;i <= n;i += 2){
                flag |= (a[i]%2 == 0);
            }
            puts(flag?"2":"1");
        }
    }
    return 0;
}