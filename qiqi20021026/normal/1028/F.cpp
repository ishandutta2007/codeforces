#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define N 300000
#define P(x,y) make_pair(x,y)
#define ff first
#define ss second

LL m,op,x,y,sum,cnt;
map<LL,LL> vis;
map<LL,LL> num[N],num2[N];
set<pair<LL,LL> > se[N];

LL gcd(LL x,LL y){return y==0?x:gcd(y,x%y);}

int main(){
	scanf("%lld",&m);
	while (m--){
		scanf("%lld%lld%lld",&op,&x,&y);
		if (op==1){
			++sum;
			LL t=x*x+y*y,k;
			if (!vis[t])
				vis[t]=++cnt;
			k=vis[t];
			for (auto i=se[k].begin();i!=se[k].end();++i){
				LL dx=(*i).ff,dy=(*i).ss;
				dx+=x; dy+=y;
				LL d=gcd(dx,dy); dx/=d; dy/=d;
				++num[dx][dy];
			}
			se[k].insert(P(x,y));
			LL d=gcd(x,y); x/=d; y/=d;
			++num2[x][y];
		}
		if (op==2){
			--sum;
			LL t=x*x+y*y,k;
			k=vis[t];
			se[k].erase(P(x,y));
			for (auto i=se[k].begin();i!=se[k].end();++i){
				LL dx=(*i).ff,dy=(*i).ss;
				dx+=x; dy+=y;
				LL d=gcd(dx,dy); dx/=d; dy/=d;
				--num[dx][dy];
			}
			LL d=gcd(x,y); x/=d; y/=d;
			--num2[x][y];
		}
		if (op==3){
			LL d=gcd(x,y); x/=d; y/=d;
			printf("%lld\n",sum-num[x][y]*2-num2[x][y]);
		}
	}
	
	return 0;
}