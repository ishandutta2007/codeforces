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

const int MAXN = 1000+5;
std::map<std::string,int> S;
std::string str[MAXN];
int score[MAXN][51],id[MAXN],tot;
const int sc[] = {0, 25, 18, 15, 12, 10, 8, 6, 4, 2, 1};

inline bool cmp(int x,int y){
    FOR(i,0,50){
        if(score[x][i] < score[y][i]) return 1;
        if(score[x][i] > score[y][i]) return 0;
    }
    return 0;
}

int main(){
    std::ios::sync_with_stdio(false);
    int t;std::cin >> t;
    while(t--){
        int n;std::cin >> n;
        FOR(i,1,n){
            std::string tmp;std::cin >> tmp;
            if(!S.count(tmp)) S[tmp] = ++tot,str[tot] = tmp;
            int id = S[tmp];
            ++score[id][i];
            if(i <= 10) score[id][0] += sc[i];
        }
    }
    int id = 1;FOR(i,2,tot) if(cmp(id,i)) id = i;
    std::cout << str[id] << '\n';
    FOR(i,1,tot) std::swap(score[i][0],score[i][1]);
    id = 1;FOR(i,2,tot) if(cmp(id,i)) id = i;
    std::cout << str[id] << '\n';
    return 0;
}