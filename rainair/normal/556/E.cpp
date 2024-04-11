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
#define P std::pair<char,int>
#define Re register
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

std::map<int,P> S;

int n,q;
int main(){
    scanf("%d%d",&n,&q);
    S[0] = MP('U',0);S[n+1] = MP('L',0);
    while(q--){
        int x,y,ans=0;char ch[12];
        scanf("%d%d%s",&x,&y,ch+1);
        auto iter = S.lower_bound(x);
        if(x == iter->fi) ans = 0;
        else{
            if(ch[1] == 'L') iter--;
            ans = std::abs(iter->first-x);
            if(iter->second.first == ch[1]){
                ans += iter->second.second;
            }
            S[x] = MP(ch[1],ans);
        }
        printf("%d\n",ans);
    }
    return 0;
}