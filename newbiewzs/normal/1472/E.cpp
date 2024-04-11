#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n;
struct node{
	int x,y,id,flag;
}a[500005];
int top;
int x,y,jl;
int ans[500005];
int cmp(node x,node y){
	if(x.x!=y.x)return x.x<y.x;
}
signed main(){
	cin>>T;
	while(T--){
		scanf("%lld",&n);top=0;
		for(int i=1;i<=n*2+5;i++){
			a[i].x=a[i].y=a[i].flag=a[i].id=0;
		}
		for(int i=1;i<=n;i++){
			top++;
			a[top].flag=0;
			scanf("%lld%lld",&a[top].x,&a[top].y);
			a[top].id=i;
			top++;
			a[top]=a[top-1];
			swap(a[top].x,a[top].y);
			a[top].flag=1;
		}
		sort(a+1,a+top+1,cmp);
		int minn=2e9;
		int jll=2e9;
		int zss=2e9;
		for(int i=1;i<=top;i++){
			if(minn<a[i].y){
				ans[a[i].id]=jl;
			}
			zss=2e9;
			while(a[i+1].x==a[i].x and i<top){
				if(a[i].y<zss and a[i].flag==0){
					zss=a[i].y;
					jll=a[i].id;
				}
				i++;
				if(minn<a[i].y)ans[a[i].id]=jl;
			}
			if(minn>zss){
				minn=zss;
				jl=jll;
			}
			if(a[i].flag==0 and a[i].y<minn){
				jl=a[i].id;
				minn=a[i].y;
			}
		}
		for(int i=1;i<=n;i++){
			if(!ans[i])printf("-1 ");
			else printf("%lld ",ans[i]);
		}
		puts("");
		for(int i=1;i<=n*2+5;i++)ans[i]=0;
	}
	return 0;
}