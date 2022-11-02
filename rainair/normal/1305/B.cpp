/*
 * Author: RainAir
 * Time: 2020-03-03 22:41:46
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
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1000+5;
char str[MAXN];
bool del[MAXN];

int main(){
    scanf("%s",str+1);int n = strlen(str+1);
    int r = n,l = 1;
    while(l <= n){
        if(l > r) break;
        while(str[l] == ')') l++;
        while(str[r] == '(') r--;
        if(l <= r){
            del[l] = 1;del[r] = 1;
            l++;r--;
        }
    }
    std::vector<int> ans;
    FOR(i,1,n) if(del[i]) ans.pb(i);
    if(ans.empty()){
        puts("0");
        return 0;
    }
    puts("1");
    printf("%d\n",(int)ans.size());
    for(auto x:ans) printf("%d ",x);
    puts("");
    return 0;
}