#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb push_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e5 + 5;
const int prime[] = {0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
int a[MAXN];
std::vector<int> ans;

int main(){
    int n;scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    ans.pb(a[1]);
    FOR(i,2,n){
        if(std::__gcd(a[i-1],a[i]) == 1){
            ans.pb(a[i]);
        }
        else{
            FOR(j,1,15){
                if(a[i]%prime[j] && a[i-1]%prime[j]){
                    ans.pb(prime[j]);
                    ans.pb(a[i]);break;
                }
            }
        }
    }
    printf("%d\n",SZ(ans)-n);
    for(auto x:ans) printf("%d ",x);puts("");
    return 0;
}