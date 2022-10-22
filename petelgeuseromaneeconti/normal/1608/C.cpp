#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=100005,INF=0X3F3F3F3F;
int T,n,a[N],b[N],id[N],ans[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		rep(i,1,n)scanf("%d",&a[i]);
		rep(i,1,n)scanf("%d",&b[i]),id[i]=i;
		sort(id+1,id+1+n,[&](int x,int y){return a[x]<a[y];});
		int mx=0,mn=INF;
		int lst=n;
		per(_,n,1){
			int i=id[_];
			if(mx>b[i]&&mn>b[i]){
				ans[i]=0;
			}else{
				while(lst>=_){
					ans[id[lst]]=1;
					mn=min(mn,b[id[lst]]);
					--lst;
				}
			}
			mx=max(mx,b[i]);
		}
		rep(i,1,n)putchar(ans[i]+48);
		puts("");
	}
	return 0;
}