/*
 * Author: RainAir
 * Time: 2020-03-05 10:25:07
 */
#include<bits/stdc++.h>

#define fi first
#define se second
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

const int MAXN = 1e5 + 5;

char str[MAXN];
int n;

struct AM{
    int ch[MAXN][26],frm[MAXN],tot = 0,rt = 0;

    inline void build(){
        CLR(ch,0);CLR(frm,0x3f);
        FOR(i,1,n) frm[str[i]-'a'] = std::min(frm[str[i]-'a'],i);
        ROF(i,n,0){
            if(i < n){
                ch[i][str[i+1]-'a'] = i+1;
            }
            FOR(j,0,25){
                if(!ch[i+1][j]&&!ch[i][j]) ch[i][j] = frm[j];
                else if(!ch[i][j]) ch[i][j] = ch[i+1][j];
            }
        }
    }
}am;
char T[MAXN];
int main(){
    int t;scanf("%d",&t);
    while(t--){
        scanf("%s",str+1);scanf("%s",T+1);
        n = strlen(str+1);int m = strlen(T+1);
        am.build();
        bool flag = 0;int ans = 1,v = 0;
        FOR(i,1,m){
            int x = T[i]-'a';
            if(am.ch[v][x] == 0x3f3f3f3f){
                flag = true;break;
            }
            else{
                if(am.ch[v][x] <= v) ans++;
                v = am.ch[v][x];
            }
        }
        printf("%d\n",flag?-1:ans);
    }
    return 0;
}