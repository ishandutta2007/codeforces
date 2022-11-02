/*
 * Author: RainAir
 * Time: 2020-03-03 09:59:00
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

const int MAXN = 100+5;
std::string str[MAXN];
int n,m;
std::map<std::string,int> S;

inline bool chk(std::string str){
    FOR(i,0,(int)str.length()-1){
        if(str[i] != str[str.length()-1-i]) return false;
    }
    return true;
}
std::string pre,ans;
int main(){
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    FOR(i,1,n) std::cin >> str[i];
    FOR(i,1,n) S[str[i]]++;
    FOR(i,1,n){
        if(!S[str[i]]) continue;
        std::string now = str[i];
        std::reverse(all(now));
        S[str[i]]--;
        if(S[now]) S[now]--,pre += str[i];
        else S[str[i]]++;
    }
    std::string mid;bool flag = true;
    int len = 0;
    for(auto x:S){
        if(!x.se) continue;
        if(chk(x.fi)){
            flag = true;
            if((int)x.fi.length() < len) continue;
            len = x.fi.length();mid = x.fi;
        }
    }
    std::string suf = pre;std::reverse(all(suf));
    std::string ans = pre+mid+suf;
    std::cout << ans.length() << std::endl;
    std::cout << ans << std::endl;
    return 0;
}