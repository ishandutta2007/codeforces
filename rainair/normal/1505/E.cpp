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

const int MAXN = 50+5;
char str[MAXN][MAXN];
int n,m;
std::vector<int> S;

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%s",str[i]+1);
    int x = 1,y = 1,s = str[1][1]=='*';
    while(x != n || y != m){
        if(x == n){
            ++y;
            s += str[x][y]=='*';
            continue;
        }
        if(y == m){
            ++x;
            s += str[x][y]=='*';
            continue;
        }
        if(str[x+1][y] == str[x][y+1]){
            ++y;
            s += str[x][y]=='*';
            continue;
        }
        if(str[x+1][y] == '*'){
            ++x;
        }
        else{
            ++y;
        }
        s += str[x][y]=='*';
    }
    printf("%d\n",s);
    return 0;
}