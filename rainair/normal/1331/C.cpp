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

//And after happily lived ever they
//And they lived happily ever after
int main(){
    int t[66] = {0};
    int n;scanf("%d",&n);
    FOR(i,0,5) t[5-i] = (n>>i)&1;
    int ans = 0;
    ans |= (t[0]<<5);
    ans |= (t[5]<<4);
    ans |= (t[3]<<3);
    ans |= (t[2]<<2);
    ans |= (t[4]<<1);
    ans |= (t[1]);
    printf("%d\n",ans);
    return 0;
}