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
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 200+5;
char ans[MAXN],str[MAXN];
bool used[MAXN];

int now;
int p1,p2;int n;

inline bool chk(){
    CLR(used,0);used[str[p1]-'a'] = used[str[p2]-'a'] = 1;
    FOR(i,p2+1,n){
        if(str[i] == ans[now]) continue;
        if(str[i] == ans[now-1]){
            now--;continue;
        }
        if(str[i] == ans[now+1]){
            now++;continue;
        }
        if(used[str[i]-'a']) return false;
        if(now != 1 && ans[now-1] == 0){
            ans[now-1] = str[i];now--;used[str[i]-'a'] = 1;
            continue;
        }
        if(now != n && ans[now+1] == 0){
            ans[now+1] = str[i];now++;used[str[i]-'a'] = 1;
            continue;
        }
        return false;
    }
    return true;
}

inline bool Solve(){
    p1=1,p2=2;
    FOR(i,1,n){
        if(i != 1){
            CLR(ans,0);
            ans[i] = str[p1];
            ans[i-1] = str[p2];now = i-1;
            if(chk()) return true;
        }
        if(i != n){
            CLR(ans,0);
            ans[i] = str[p1];
            ans[i+1] = str[p2];now = i+1;
            if(chk()) return true;
        }
    }
    return false;
}

int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%s",str+1);n = strlen(str+1);
        if(n == 1){
            int now = 'a';puts("YES");
            putchar(str[1]);
            FOR(i,2,26){
                if(now == str[1]) now++;
                putchar(now);now++;
            }puts("");
            continue;
        }
        if(Solve()){
            puts("YES");
            FOR(i,1,26){
                if(ans[i] != 0) putchar(ans[i]);
                else{
                    FOR(j,0,25){
                        if(used[j]) continue;
                        used[j] = true;putchar('a'+j);break;
                    }
                }
            }puts("");
        }
        else{
            puts("NO");continue;
        }
    }
    return 0;
}