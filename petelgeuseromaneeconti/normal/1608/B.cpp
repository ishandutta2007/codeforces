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
		int n,a,b;
		scanf("%d%d%d",&n,&a,&b);
		if(abs(a-b)>1){
			puts("-1");
			continue;
		}
		int L=1,R=n;
		vector<int>v;
		if(a>b){
			v.pb(L++);
			while(a--){
				v.pb(R--);
				if(!a)v.pb(R--);
				else v.pb(L++);
			}
			while(L<=R){
				v.pb(R--);
			}
		}else if(a<b){
			v.pb(R--);
			while(b--){
				v.pb(L++);
				if(!b)v.pb(L++);
				else v.pb(R--);
			}
			while(L<=R){
				v.pb(L++);
			}
		}else{
			++a;
			while(a--){
				v.pb(L++);
				if(!a)v.pb(L++);
				else v.pb(R--);
			}
			while(L<=R){
				v.pb(L++);
			}
		}
		if(SZ(v)>n){
			puts("-1");
		}else{
			for(auto&x:v)printf("%d ",x);
			puts("");
		}
	}
	return 0;
}