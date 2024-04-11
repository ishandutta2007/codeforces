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
const int MAXM = 30;
// 0..30
std::multiset<int> S[MAXM+1];
LL sm[MAXM+1];
// [2^i,2^{i+1})
int n;

inline int getid(int x){
    ROF(i,MAXM,0) if((x>>i)&1) return i;
}

int main(){
    scanf("%d",&n);int sz=0;
    while(n--){
        char s[12];scanf("%s",s+1);
        if(s[1] == '+'){
            int x;scanf("%d",&x);
            int t = getid(x);
            sm[t] += x;S[t].insert(x);++sz;
        }
        else{
            int x;scanf("%d",&x);--sz;
            int t = getid(x);
            sm[t] -= x;S[t].erase(S[t].find(x));
        }
        LL now = 0;int ans = 0;
        FOR(i,0,MAXM){
            if(S[i].empty()) continue;
            if(*S[i].begin() > 2*now) ans++;
            now += sm[i];
        }
        printf("%d\n",sz-ans);
    }
    return 0;
}