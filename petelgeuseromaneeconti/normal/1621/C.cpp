#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		auto query=[&](int x){
			printf("? %d\n",x);
			fflush(stdout);
			int y;
			scanf("%d",&y);
			return y;
		};
		vector<int>p(n+1);
		rep(i,1,n)if(!p[i]){
			int cur=query(i);
			vector<int>v={cur};
			while(1){
				int nex=query(i);
				if(nex==cur)break;
				v.pb(nex);
			}
			//rotate(v.begin(),find(v.begin(),v.end(),cur),v.end());
			rep(i,0,SZ(v)-1){
				p[v[i]]=v[(i+1)%SZ(v)];
			}
		}
		printf("! ");
		rep(i,1,n)printf("%d ",p[i]);
		puts("");
		fflush(stdout);
	}
	return 0;
}