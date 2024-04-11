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

int main(){
	int T;scanf("%d",&T);
	while(T--){
		int p,f,cs,cw,s,w;
		scanf("%d%d%d%d%d%d",&p,&f,&cs,&cw,&s,&w);
		if(s > w) std::swap(s,w),std::swap(cs,cw);
		int ans = 0;
		FOR(i,0,std::min(p/s,cs)){
			int x1 = i,y1 = std::min(cw,(p-i*s)/w);
			int x2 = std::min(cs-x1,f/s),y2 = std::min(cw-y1,(f-x2*s)/w);
			ans = std::max(ans,x1+y1+x2+y2);		
		}
		printf("%d\n",ans);
	}
	return 0;
}