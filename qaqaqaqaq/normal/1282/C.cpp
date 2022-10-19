#include<bits/stdc++.h>
#define int long long
#define S second
#define F first
using namespace std;
 
const int maxn=200007;
int n,T,a,b,ans,e[2];
pair<int,int> p[maxn]; 

int calc(int u){
    if (u<=a*e[0]) return u/a;
    else if (u<=a*e[0]+b*e[1]) return e[0]+(u-a*e[0])/b;
    return e[0]+e[1];
}
#undef int
int main(){
    int _;
    scanf("%d",&_);
    while (_--){
        e[0]=e[1]=0;
        scanf("%d%d%d%d",&n,&T,&a,&b);
        for (int i=0;i<n;++i) scanf("%d",&p[i].S), e[p[i].S]++; 
        for (int i=0;i<n;++i) scanf("%d",&p[i].F);
        sort(p,p+n);
        p[n].F=T+1;
        long long i=0,cnt=0;
        ans=max(0ll,calc(p[0].F-1));
        while (i<n){
            cnt+=p[i].S?b:a;
            e[p[i].S]--;
            while (i<n&&p[i].F==p[i+1].F) cnt+=(p[i+1].S?b:a), i++, e[p[i].S]--;
            if (cnt<p[i+1].F) ans=max(ans,i+1+calc(p[i+1].F-1-cnt));
            i++;
        }
        printf("%d\n",ans);
    }
    return 0;
}