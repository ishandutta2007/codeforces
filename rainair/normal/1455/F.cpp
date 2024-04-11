#include <bits/stdc++.h>

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

const int MAXN = 500+5;
int n,k;
int mn[26];
std::string f[MAXN],str;

inline std::string ctos(char x){
    return std::string(1,x);
}

inline void Solve(){
    std::cin >> n >> k >> str;str = "0"+str;
    mn[0] = 0;FOR(i,1,k-2) mn[i] = i-1;mn[k-1] = 0;
    f[0].clear();FOR(i,1,n) f[i] = "{";
    FOR(i,0,n-1){
        f[i+1] = std::min(f[i+1],f[i]+ctos('a'+mn[str[i+1]-'a']));
        if(i) f[i+1] = std::min(f[i+1],f[i].substr(0,i-1)+ctos(str[i+1])+f[i].back());
        if(i != n-1) f[i+2] = std::min(f[i+2],f[i]+ctos('a'+mn[str[i+2]-'a'])+ctos(str[i+1]));
        if(i && i != n-1) f[i+2] = std::min(f[i+2],f[i].substr(0,i-1)+ctos(str[i+2])+f[i].back()+ctos(str[i+1]));
    }
    std::cout << f[n] << std::endl;
}

int main(){
    std::ios::sync_with_stdio(false);
    int T;std::cin >> T;
    while(T--) Solve();
    return 0;
}