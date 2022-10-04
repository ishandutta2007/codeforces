#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define ll long long
typedef pair<int,int> pii;
inline int Gcd(int X,int Y){return Y?Gcd(Y,X%Y):X;}

int n;
int inp[100001],p[100001],pc,g[100001],h[100001];

void init(){
	inp[0]=inp[1]=1;
	g[1]=1;
	F(i,2,100000){
		if(!inp[i]) p[++pc]=i, g[i]=2, h[i]=1;
		for(int j=1;j<=pc&&p[j]*i<=100000;++j){
			inp[i*p[j]]=1;
			if(i%p[j]) g[i*p[j]]=g[i]*2, h[i*p[j]]=1;
			else {g[i*p[j]]=g[i]/(h[i]+1)*(h[i]+2); h[i*p[j]]=h[i]+1; break;}
		}
	}
}

int main(){
	init();
	int T;
	scanf("%d",&T);
	while(T--){
		int A,B,C;
		scanf("%d%d%d",&A,&B,&C);
		int f[8];
		f[1]=A; f[2]=B; f[4]=C;
		f[3]=Gcd(A,B);
		f[5]=Gcd(A,C);
		f[6]=Gcd(B,C);
		f[7]=Gcd(A,Gcd(B,C));
		ll Ans1=0,Ans2=0;
		F(S,1,(1<<6)-1){
			int X=0,Y=0,Z=0,Cnt=-1;
			if(S>>0&1) X|=1, Y|=2, Z|=4, Cnt=-Cnt;
			if(S>>1&1) X|=1, Y|=4, Z|=2, Cnt=-Cnt;
			if(S>>2&1) X|=2, Y|=1, Z|=4, Cnt=-Cnt;
			if(S>>3&1) X|=2, Y|=4, Z|=1, Cnt=-Cnt;
			if(S>>4&1) X|=4, Y|=1, Z|=2, Cnt=-Cnt;
			if(S>>5&1) X|=4, Y|=2, Z|=1, Cnt=-Cnt;
			Ans1=Ans1+(ll)Cnt*g[f[X]]*g[f[Y]]*g[f[Z]];
			Ans2=Ans2+(ll)Cnt*(g[f[X|Y]]*g[f[Z]]+g[f[X|Z]]*g[f[Y]]+g[f[Y|Z]]*g[f[X]]);
		}
		ll Ans3=2*g[f[7]];
		printf("%lld\n",(Ans1+Ans2+Ans3)/6);
	}
	return 0;
}