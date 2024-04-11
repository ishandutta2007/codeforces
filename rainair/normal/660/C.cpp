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

const int MAXN = 3e5 + 5;
int n,k;
int a[MAXN];
std::set<P<int,int> > S;

int main(){
    scanf("%d%d",&n,&k);
    FOR(i,1,n) scanf("%d",a+i),a[i] = !a[i];
    int l = 1,sm = 0;
    int ansl = 1,ansr = 0;
    FOR(r,1,n){
        sm += a[r];
        while(l <= r && sm > k) sm -= a[l++];
        if(l <= r && r-l > ansr-ansl){
            ansl = l;ansr = r;
        }
    }
    printf("%d\n",ansr-ansl+1);
    FOR(i,1,n){
        if(ansl <= i && i <= ansr) printf("1 ");
        else printf("%d ",(!a[i]));
    }
    puts("");
    return 0;
}