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

const int MAXN = 5e5 + 5;
int n;
int opt[MAXN],x[MAXN];
char str[23];

int main(){
    scanf("%d",&n);
    FOR(i,1,2*n){
        scanf("%s",str);
        if(str[0] == '+') continue;
        opt[i] = 1;scanf("%d",x+i);
    }
    std::vector<int> ans;
    std::set<int> S;
    ROF(i,2*n,1){
        if(opt[i] == 0){
            if(S.empty()){
                puts("NO");
                exit(0);
            }
            ans.pb(*S.begin());
            S.erase(S.begin());
        }
        else{
            if(!S.empty() && *S.begin() < x[i]){
                puts("NO");
                exit(0);
            }
            S.insert(x[i]);
        }
    }
    std::reverse(all(ans));
    puts("YES");
    for(auto x:ans) printf("%d ",x);puts("");
    return 0;
}