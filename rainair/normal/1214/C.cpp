/*
 * Author: RainAir
 * Time: 2019-09-04 17:23:51
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

const int MAXN = 2e5 + 5;
char str[MAXN];
int n;
std::stack<char> S;

int main(){
    scanf("%d",&n);
    scanf("%s",str+1);
    int lb=0,rb = 0;
    FOR(i,1,n){
        if(str[i] == '(') lb++;
        else rb++;
    }
    if(lb != rb){
        puts("No");
        return 0;
    }
    bool flag = false;
    FOR(i,1,n){
        if(str[i] == '(') S.push('(');
        else{
            if(!S.empty()){
                S.pop();
            }
            else{
                if(flag){
                    puts("No");
                    return 0;
                }
                flag = true;
            }
        }
    }
    puts("Yes");
    return 0;
}