#include <stdio.h>
#include <string.h>
#include <algorithm>
#define int LL
typedef long long LL;
struct xxx{
	int p,tp;
}x[6],y[6];
bool operator < (xxx a,xxx b){
	if(a.p==b.p) return a.tp<b.tp;
	return a.p<b.p;
}
int a[6][6],nbx[2],nby[2],nwx[2],nwy[2],ans[2];
void calc(int xa,int ya,int xb,int yb,int tp){
	int sz=(xb-xa)*(yb-ya);
	if(tp==0){
		ans[0]+=(sz>>1);
		ans[1]+=(sz>>1);
		if(((xb-xa)&1)&&((yb-ya)&1)){
			if((xa&1)^(ya&1)){
				ans[1]++;
			}else{
				ans[0]++;
			}
		}
	}
	if(tp==1){
		ans[0]+=sz;
	}
	if(tp==2){
		ans[1]+=sz;
	}
}
signed main(){
	int T; scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld",&y[5].p,&x[5].p);
		x[5].p++,y[5].p++;
		x[0].p=1,y[0].p=1;
		y[0].tp=y[5].tp=x[0].tp=x[5].tp=0;
		scanf("%lld%lld%lld%lld",&x[1].p,&y[1].p,&x[2].p,&y[2].p);
		x[2].p++,y[2].p++;
		y[1].tp=y[2].tp=x[1].tp=x[2].tp=1;
		scanf("%lld%lld%lld%lld",&x[3].p,&y[3].p,&x[4].p,&y[4].p);
		x[4].p++,y[4].p++;
		y[3].tp=y[4].tp=x[3].tp=x[4].tp=2;
		std::sort(x,x+6),std::sort(y,y+6);
		memset(a,0,sizeof(a));
		ans[0]=ans[1]=0;
		//x
		for(int i=0;i<6;i++)
			if(x[i].tp==1){nwx[0]=i;break;}
		for(int i=0;i<6;i++)
			if(x[i].tp==2){nbx[0]=i;break;}
		for(int i=5;i>=0;i--)
			if(x[i].tp==1){nwx[1]=i;break;}
		for(int i=5;i>=0;i--)
			if(x[i].tp==2){nbx[1]=i;break;}
		//y
		for(int i=0;i<6;i++)
			if(y[i].tp==1){nwy[0]=i;break;}
		for(int i=0;i<6;i++)
			if(y[i].tp==2){nby[0]=i;break;}
		for(int i=5;i>=0;i--)
			if(y[i].tp==1){nwy[1]=i;break;}
		for(int i=5;i>=0;i--)
			if(y[i].tp==2){nby[1]=i;break;}
		for(int i=nwx[0];i<nwx[1];i++)
			for(int j=nwy[0];j<nwy[1];j++)
				a[i][j]=1;
		for(int i=nbx[0];i<nbx[1];i++)
			for(int j=nby[0];j<nby[1];j++)
				a[i][j]=2;
		for(int i=0;i<5;i++)
			for(int j=0;j<5;j++)
				calc(x[i].p,y[j].p,x[i+1].p,y[j+1].p,a[i][j]);
		printf("%lld %lld\n",ans[0],ans[1]);
	}
}