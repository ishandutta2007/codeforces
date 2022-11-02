#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair
#define LL long long
#define pb push_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e6 + 5;
char str[MAXN],st[MAXN];int tp;
int n;

inline int getid(char x){
    if(x == '<') return -1;
    if(x == '>') return 1;
    if(x == '{') return -2;
    if(x == '}') return 2;
    if(x == '[') return -3;
    if(x == ']') return 3;
    if(x == '(') return -4;
    if(x == ')') return 4;
}

int main(){
    scanf("%s",str+1);n = strlen(str+1);
    int ans = 0;
    FOR(i,1,n){
        int o = getid(str[i]);
        if(o < 0){
            st[++tp] = o;
        }
        else{
            if(!tp){
                puts("Impossible");
                return 0;
            }
            if(-st[tp] == o){
                --tp;
            }
            else{
                ++ans;
                --tp;
            }
        }
    }
    if(tp){
        puts("Impossible");
        return 0;
    }
    printf("%d\n",ans);
    return 0;
}