#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define dF2(i,a,b) for(int i=a;i>(b);--i)
#define eF(i,u) for(int i=h[u];i;i=nxt[i])
#define ll long long
#define ld double
using namespace std;
const ll INF=0x3f3f3f3f;

ll Abs(ll x){return x>=0?x:-x;}
ll n,m,q,cl,ce,v;
ll ls[100005],es[100005];

int main(){
	scanf("%I64d%I64d%I64d%I64d%I64d",&n,&m,&cl,&ce,&v);
	F(i,1,cl) scanf("%I64d",ls+i);
	F(i,1,ce) scanf("%I64d",es+i);
	scanf("%I64d",&q);
	F(i,1,q){
		ll sx,sy,tx,ty,lenx,Ans=INF<<5;
		scanf("%I64d%I64d%I64d%I64d",&sx,&sy,&tx,&ty);
		if(sx==tx){printf("%I64d\n",Abs(sy-ty));continue;}
		if(sy>ty) swap(sy,ty), swap(sx,tx);
		// sy < ty
		lenx=Abs(sx-tx);
		int pos1=lower_bound(ls+1,ls+cl+1,sy)-ls;
		if(1<=pos1&&pos1<=cl){
			if(ls[pos1]<=ty) Ans=min(Ans,lenx+ty-sy);
			else Ans=min(Ans,lenx+ty-sy+2*(ls[pos1]-ty));
		}
		--pos1;
		if(1<=pos1&&pos1<=cl){
			Ans=min(Ans,lenx+ty-sy+2*(sy-ls[pos1]));
		}
		pos1=lower_bound(es+1,es+ce+1,sy)-es;
		if(1<=pos1&&pos1<=ce){
			if(es[pos1]<=ty) Ans=min(Ans,(lenx-1)/v+1+ty-sy);
			else Ans=min(Ans,(lenx-1)/v+1+ty-sy+2*(es[pos1]-ty));
		}
		--pos1;
		if(1<=pos1&&pos1<=ce){
			Ans=min(Ans,(lenx-1)/v+1+ty-sy+2*(sy-es[pos1]));
		}
		printf("%I64d\n",Ans);
	}
	return 0;
}