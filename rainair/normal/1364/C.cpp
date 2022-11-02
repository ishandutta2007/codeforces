/*
 * Author: RainAir
 * Time: 2020-05-29 15:46:11
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

const int MAXN = 3e5 + 5;
int n,a[MAXN],b[MAXN];

int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,2,n){
        if(a[i] < a[i-1]){
            puts("-1");
            return 0;
        }
    }
    std::vector<int> S;
    if(a[1] == 0) S.pb(1);
    else if(a[1] == 1) b[1] = 0;
    else{
        puts("-1");
        return 0;
    }
    FOR(i,2,n){
        S.pb(i);
        if(a[i] == a[i-1]){
            continue;
        }
        else{
            int d = a[i]-a[i-1];
            if((int)S.size() < d){
                puts("-1");return 0;
            }
            FOR(j,0,d-1){
                b[S.back()] = a[i-1]+j;
                S.pop_back();
            }
        }
    }
    for(auto x:S) b[x] = 1e6-1;//puts("Yes");
    FOR(i,1,n) printf("%d ",b[i]);puts("");
    return 0;
}