#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define pii pair<int,int>
#define se second
using namespace std;
const int N=5e5+9;
int vis[N];
set<pii> S;
int main(){
	int T;
	scanf("%d",&T);
	int cnt=0,p=1;
	while(T--){
		int op;
		scanf("%d",&op);
		if(op==1){
			++cnt;
			int m;
			scanf("%d",&m);
			S.insert({-m,cnt});
		}
		if(op==2){
			while(vis[p])++p;
			vis[p]=1;
			printf("%d ",p);
		}
		if(op==3){
			auto it=S.begin();
			while(it!=S.end()){
				auto w=*it;
				++it;
				S.erase(w);
				if(vis[w.se])continue;
				vis[w.se]=1;
				printf("%d ",w.se);
				break;
			}
		}
	}
}