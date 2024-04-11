//luogu PinkRabbit
#include<bits/stdc++.h>
#define F2(i,a,b) for(int i=a;i<(b);++i)

char str[1000005];
int n,q;
struct Perm{int*per;}Left,Tmp,Now;
inline void I(Perm&P){F2(i,0,n) P.per[i]=i;}
Perm operator*(Perm P1,Perm P2){
	Perm Ans; Ans.per=(int*)malloc(4*n);
	F2(i,0,n) Ans.per[i]=P1.per[P2.per[i]];
	return Ans;
}
Perm operator^(Perm B,int E){
	Perm Ans; Ans.per=(int*)malloc(4*n); I(Ans);
	for(;E;E>>=1,B=B*B) if(E&1) Ans=Ans*B;
	return Ans;
}

int main(){
	int k,d;
	scanf("%s%d",str,&q); n=strlen(str);
	Left.per=(int*)malloc(4*n);
	Tmp.per=(int*)malloc(4*n);
	Now.per=(int*)malloc(4*n);
	F2(i,0,n) i[Left.per]=i+1; Left.per[n-1]=0;
	I(Now);
	F2(i,0,q){
		scanf("%d%d",&k,&d);
		I(Tmp);
		int now=0;
		F2(j,0,d) for(int g=j;g<k;g+=d) Tmp.per[now++]=g;
		Tmp=((Tmp*Left)^(n-k+1))*(Left^(k-1));
		Now=Now*Tmp;
		F2(i,0,n) putchar(i[Now.per][str]); puts("");
	}
	return 0;
}