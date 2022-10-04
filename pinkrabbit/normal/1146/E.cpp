#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define MN 300005
#define MM 600005
int n,q,a[MN],b[MN];
int stk[MN],typ[MN],rv[MN],tp,rev;
inline void push(int x,int t,int r){
	while(tp&&stk[tp]>=x)r^=rv[tp--];
	stk[++tp]=x,typ[tp]=t,rv[tp]=0;
	if(tp-1&&r)rv[tp-1]^=1;
}
int main(){
	scanf("%d%d",&n,&q);
	F(i,1,n)scanf("%d",a+i);
	stk[tp=1]=100001;
	F(i,1,q){
		char ch[3];int x;
		scanf("%s%d",ch,&x);
		if(*ch=='>'){
			if(x>=0)push(x+1,-1,0);
			else rev^=1,push(-x,-1,1);
		}
		else{
			if(x<=0)push(-x+1,1,0);
			else rev^=1,push(x,1,1);
		}
	}
	stk[++tp]=100001,typ[tp]=1,rv[tp]=0;
	dF(i,tp-1,1)rv[i]^=rv[i+1],typ[i]*=rv[i]?-1:1;
//	F(i,1,tp-1)printf("[%d-%d]:%d\n",stk[i],stk[i+1]-1,typ[i]);
	F(i,1,tp-1)F(j,stk[i],stk[i+1]-1)b[j]=typ[i];
	F(i,1,n){
		if(abs(a[i])<stk[1])printf("%d ",(rev?-1:1)*a[i]);
		else printf("%d ",b[abs(a[i])]*abs(a[i]));
	}
	return 0;
}