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

const int MAXN = 2e5 + 5;
char str[MAXN];
int n;
int st[MAXN];
int  tp;

inline void Solve(){
    scanf("%s",str+1);n = strlen(str+1);
    std::vector<int> S;tp=0;
    FOR(i,1,n){
        bool f1 = (i-2>0)&&str[i-2]=='t'&&str[i-1]=='w'&&str[i]=='o';
        bool f2 = str[i]=='o'&&str[i+1]=='n'&&str[i+2]=='e'&&i+2 <= n;
        if(f1&&f2){
            S.pb(i);
        }
        else if(f1){
            S.pb(i-1);
        }
        else if(f2){
            S.pb(i+1);
        }
    }
    printf("%d\n",(int)S.size());
    for(auto x:S) printf("%d ",x);puts("");
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}