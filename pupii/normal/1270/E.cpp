#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int x[1010],y[1010];
int main(){
	int n=gi();
	for(int i=1;i<=n;++i)x[i]=gi(),y[i]=gi();
	while(1){
		int cx=0,cy=0;
		for(int i=1;i<=n;++i)cx+=(x[i]&1),cy+=(y[i]&1);
		if(cx&&cx<n)break;
		if(cy&&cy<n)break;
		for(int i=1;i<=n;++i)x[i]>>=1,y[i]>>=1;
	}
	int c[4]={0};
	for(int i=1;i<=n;++i)++c[(x[i]&1)|((y[i]&1)<<1)];
	if((c[0]+c[3])&&(c[1]+c[2])){
		printf("%d\n",c[0]+c[3]);
		for(int i=1;i<=n;++i)if((((x[i]&1)|((y[i]&1)<<1))==0)||
								(((x[i]&1)|((y[i]&1)<<1))==3))printf("%d ",i);
	}else if(c[0]&&c[3]){
		printf("%d\n",c[0]);
		for(int i=1;i<=n;++i)if(((x[i]&1)|((y[i]&1)<<1))==0)printf("%d ",i);
	}else if(c[1]&&c[2]){
		printf("%d\n",c[1]);
		for(int i=1;i<=n;++i)if(((x[i]&1)|((y[i]&1)<<1))==1)printf("%d ",i);
	}else assert(0);
	return 0;
}