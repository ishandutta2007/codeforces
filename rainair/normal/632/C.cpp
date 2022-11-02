#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb push_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 5e4 + 4;
std::string str[MAXN];
int n;

int main(){
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    FOR(i,1,n) std::cin >> str[i];
    std::sort(str+1,str+n+1,[&](std::string a,std::string b){return a+b<b+a;});
    FOR(i,1,n) std::cout << str[i];std::cout << '\n';
    return 0;
}