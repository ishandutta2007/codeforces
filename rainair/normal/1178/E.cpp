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
#define Re register
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e6 + 5;
char str[MAXN],t;
std::vector<char> out;
std::map<char,int> S;
int n;

int main(){
    scanf("%s",str+1);n = strlen(str+1);
    int l = 1,r = n;
    while(l + 3 <= r){
        S.clear();S[str[l]]++;S[str[r]]++;
        S[str[l+1]]++;S[str[r-1]]++;
        t = S['a'] >= 2 ? 'a' : ((S['b'] >= 2 ? 'b' : 'c'));
        out.pb(t);++l;l++;--r;r--;
    }
    for(auto x:out) putchar(x);std::reverse(all(out));
    if(l < r) putchar(str[l]);for(auto x:out) putchar(x);
    puts("");
    return 0;
}