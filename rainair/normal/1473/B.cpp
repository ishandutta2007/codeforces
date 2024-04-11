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

int main(){
    std::ios::sync_with_stdio(false);
    int T;std::cin >> T;
    while(T--){
        std::string s1,s2;
        std::cin >> s1 >> s2;
        if(SZ(s1) > SZ(s2)) std::swap(s1,s2);
        int t = std::__gcd(SZ(s1),SZ(s2));
        std::string s;
        FOR(i,1,SZ(s1)/t) s += s2;
        bool flag = 1;
        for(int l = 0,r;l < SZ(s);l = r+1){
            r = l+SZ(s1)-1;
            flag &= s1 == s.substr(l,r-l+1);
        }
        if(flag) std::cout << s << '\n';
        else std::cout << -1 << '\n';
    }
    return 0;
}