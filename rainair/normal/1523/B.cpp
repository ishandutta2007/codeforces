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

const int MAXN = 1000 + 5;
int a[MAXN],n,b[MAXN];

struct Node{
    int o,x,y;
};
std::vector<Node> ans;

int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);ans.clear();
        FOR(i,1,n) scanf("%d",a+i),b[i] = a[i];
        printf("%d\n",(n/2)*6);
        for(int i = 1;i <= n;i += 2){
            FOR(j,1,2){
                printf("1 %d %d\n",i,i+1);
                printf("2 %d %d\n",i,i+1);
                printf("1 %d %d\n",i,i+1);
                a[i] += a[i+1];
                a[i+1] -= a[i];
                a[i] += a[i+1];
            }
        }
//        FOR(i,1,n) assert(b[i] == -a[i]);
    }
    return 0;
}