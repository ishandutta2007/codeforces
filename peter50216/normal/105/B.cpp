#include<stdio.h>
struct XD{
    int lvl,loy;
    void get(){
	scanf("%d%d",&lvl,&loy);
    }
}in[10];
long double ans=0;
int n,k,lvl;
inline long double solve(){
    int i,j;
    long double aa=0;
    for(i=0;i<(1<<n);i++){
	long double p1=1;
	int ps=0;
	int kl=0;
	for(j=0;j<n;j++){
	    if(i&(1<<j)){
		p1*=in[j].loy/100.0;
		ps++;
	    }else{
		p1*=(100-in[j].loy)/100.0;
		kl+=in[j].lvl;
	    }
	}
	if(p1==0)continue;
	if(ps>n/2)aa+=p1;
	else aa+=p1*(long double)lvl/(lvl+kl);
    }
    return aa;
}
inline void dfs(int np,int pk){
    int i;
    long double d=solve();
    if(ans<d)ans=d;
    if(pk){
	for(i=np;i<n;i++){
	    if(in[i].loy==100)continue;
	    in[i].loy+=10;
	    dfs(i,pk-1);
	    in[i].loy-=10;
	}
    }
}
int main(){
    int i;
    scanf("%d%d%d",&n,&k,&lvl);
    for(i=0;i<n;i++)in[i].get();
    dfs(0,k);
    printf("%.10lf\n",(double)ans);
}