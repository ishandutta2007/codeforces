#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
using namespace std;
int n,p,q,tail;
pair<int,int> a[100010],que[100010];
double res;
int cmp(pair<int,int> x,pair<int,int> y){
	return (x.fi<y.fi||(x.fi==y.fi&&x.se>y.se));
}
int main(){
	scanf("%d%d%d",&n,&p,&q);
	for (int i=0;i<n;i++) scanf("%d%d",&a[i].fi,&a[i].se);
    sort(a,a+n,cmp);
    for (int i=0;i<n;i++){
    	while (tail>=2&&1LL*(a[i].se-que[tail].se)*(que[tail].fi-que[tail-1].fi)>=1LL*(que[tail].se-que[tail-1].se)*(a[i].fi-que[tail].fi)) tail--;
		que[++tail]=a[i];
    }
    res=max(p,q);
    for (int i=1;i<tail;i++){
		res=min(res,max(1.*p/que[i].fi,1.*q/que[i].se));
		if (1LL*que[i].se*p>1LL*que[i].fi*q&&1LL*que[i+1].se*p<1LL*que[i+1].fi*q){
			double tmp=1.*p*(1LL*que[i].se*que[i+1].fi-1LL*que[i+1].se*que[i].fi)/(1LL*q*(que[i+1].fi-que[i].fi)-1LL*p*(que[i+1].se-que[i].se));
			res=min(res,p/tmp);
		}
    }
    res=min(res,max(1.*p/que[tail].fi,1.*q/que[tail].se));
    printf("%.9f",res);
}