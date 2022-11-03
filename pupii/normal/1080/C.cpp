#include<bits/stdc++.h>
#define il inline
#define vd void
#define int ll
typedef long long ll;
il int gi(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
main(){
	int T=gi(); 
	while(T--){
		int n=gi(),m=gi(),ans1,ans2;
		ans1=ans2=n*m/2;
		if((n*m)&1)++ans1;
		int x1=gi(),y1=gi(),x2=gi(),y2=gi();
		ll s=((x2-x1+1)*(y2-y1+1))/2;
		if((((x2-x1+1)*(y2-y1+1))&1)&&((x1+y1)&1))++s;
		ans1+=s,ans2-=s;
		int x3=gi(),y3=gi(),x4=gi(),y4=gi();
		s=((x4-x3+1)*(y4-y3+1))/2;
		if((((x4-x3+1)*(y4-y3+1))&1)&&!((x3+y3)&1))++s;
		ans1-=s,ans2+=s;
		ll x5=std::max(x1,x3),y5=std::max(y1,y3),x6=std::min(x2,x4),y6=std::min(y2,y4);
		s=(y6-y5+1)*(x6-x5+1)/2;
		if(((y6-y5+1)*(x6-x5+1))&1&&((x5+y5)&1))++s;
		if(x5<=x6&&y5<=y6)ans1-=s,ans2+=s;
		printf("%lld %lld\n",ans1,ans2);
	}
	return 0;
}