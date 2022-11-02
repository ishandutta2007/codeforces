#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb emplace_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e5 + 5;
std::string str[MAXN];
int s[MAXN],n;
int id[MAXN];

int main(){
    std::ios::sync_with_stdio(false);
    std::cin >> n;std::iota(id+1,id+n+1,1);
    FOR(i,1,n){
        std::cin >> str[i];
        int x,y;std::cin >> x >> y;
        s[i] = x*100-y*50;
        FOR(j,1,5){
            int x;std::cin >> x;
            s[i] += x;
        }
    }
    std::sort(id+1,id+n+1,[&](int x,int y){return s[x] > s[y];});
    std::cout << str[id[1]] << '\n';
    return 0;
}