#include<bits/stdc++.h>
#define LL long long
using namespace std;
vector<LL> x,y;
LL ax,bx,ay,by,nowx,nowy,t;
int ans;
int main(){
	scanf("%lld%lld",&nowx,&nowy);
	scanf("%lld%lld%lld%lld",&ax,&ay,&bx,&by);
	while (nowx<20000000000000000ll&&nowy<20000000000000000ll){
		x.push_back(nowx);
		y.push_back(nowy);
		nowx=ax*nowx+bx;
		nowy=ay*nowy+by;
	}
	scanf("%lld%lld%lld",&nowx,&nowy,&t);
	for (int i=0;i<x.size();i++){
		LL tmp;
		int res;
		tmp=t-abs(nowx-x[i])-abs(nowy-y[i]);
		if (tmp<0) continue;
		res=1;
		ans=max(res,ans);
		for (int j=i-1;j>=0;j--){
			tmp=tmp-abs(x[j]-x[j+1])-abs(y[j]-y[j+1]);
			if (tmp<0) break;
			res++;
			ans=max(res,ans);
		}
		tmp=t-abs(nowx-x[i])-abs(nowy-y[i]);
		res=1;
		for (int j=i+1;j<x.size();j++){
			tmp=tmp-abs(x[j]-x[j-1])-abs(y[j]-y[j-1]);
			if (tmp<0) break;
			res++;
			ans=max(res,ans);
		}
	}
	printf("%d\n",ans);
}