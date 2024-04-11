#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
void sol(){
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	--a,--b;
	vector<int>v(n);
	vector<bool>used(n);
	v[0]=a,used[a]=1;
	v[n-1]=b,used[b]=1;
	rep(i,1,n/2-1){
		int pos=-1;
		per(j,n-1,a){
			if(!used[j]){
				pos=j;
				break;
			}
		}
		if(pos==-1){
			puts("-1");
			return;
		}
		used[pos]=1;
		v[i]=pos;
	}
	rep(i,n/2,n-2){
		int pos=-1;
		rep(j,0,b){
			if(!used[j]){
				pos=j;
				break;
			}
		}
		if(pos==-1){
			puts("-1");
			return;
		}
		used[pos]=1;
		v[i]=pos;
	}
	rep(i,0,n-1)printf("%d ",v[i]+1);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		sol();
	}
	return 0;
}