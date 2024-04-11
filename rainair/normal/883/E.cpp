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

const int MAXN = 50 + 5;
int n,m;
char s[MAXN],t[MAXN];
bool vis[26],ans[26],tmp[26];

int main(){
    scanf("%d%s%d",&n,s+1,&m);
    FOR(i,1,n) if(s[i] != '*') vis[s[i]-'a'] = 1;
    FOR(i,0,25) ans[i] = !vis[i];
    FOR(i,1,m){
        scanf("%s",t+1);
        bool flag = 1;
        FOR(j,1,n){
            flag &= !(s[j] == '*' && vis[t[j]-'a']);
            if(s[j] != '*') flag &= (s[j] == t[j]);
        }
        if(!flag) continue;CLR(tmp,0);
        FOR(j,1,n) if(s[j] == '*') tmp[t[j]-'a'] = 1;
        FOR(i,0,25) ans[i] &= tmp[i];
    }
    int res = 0;FOR(i,0,25) res += ans[i];
    printf("%d\n",res);
    return 0;
}