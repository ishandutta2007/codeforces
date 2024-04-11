#include<cstdio>
int a,b,f,k,ans;
int main(){
	scanf("%d%d%d%d",&a,&b,&f,&k);
	int now=b,dir=0;
	if(now<f||now<a-f){puts("-1");return 0;}
	now-=f;
	for(int i=1;i<k;++i){
		if(dir==0){
			if(now<a+a-f-f) ++ans,now=b;
			now-=a+a-f-f;
			if(now<0){puts("-1");return 0;}
		}
		if(dir==1){
			if(now<f+f) ++ans,now=b;
			now-=f+f;
			if(now<0){puts("-1");return 0;}
		}
		dir^=1;
	}
	if(dir==0){
		if(now<a-f) ++ans;
	}
	if(dir==1){
		if(now<f) ++ans;
	}
	printf("%d",ans);
	return 0;
}