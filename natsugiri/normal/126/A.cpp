#include<cstdio>
#include<cmath>

typedef long long ll;

ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
int ika(int t1,int t2,int y1,int y2,ll&n,ll&d){
	n=(ll)t1*y1+(ll)t2*y2;
	d=y1+y2;
	ll g=gcd(n,d);
	n/=g;
	d/=g;
	return  0;
}

int main(){
	int t[2],x[2],t0;
	int i;
	int y[2],tm;
	ll an=-1,ad=1;
	y[0]=0;y[1]=x[1];
	tm=-1;
	scanf("%d%d%d%d%d",t,t+1,x,x+1,&t0);
	int de=t0-t[0],nu=t[1]-t0;
	if(t[0]==t0){
		y[0]=x[0];
		if(t[1]==t0)y[1]=x[1];
		else y[1]=0;
	}else if(t[1]==t0){
		y[1]=x[1];
		y[0]=0;
	}else{
		for(i=1;i<=x[1];i++){
			ll p=(ll)((double)nu*i/de);
			if(p>x[0])p=x[0];
			ll aan,aad;
			ika(t[0],t[1],p,i,aan,aad);
			if(an<0||(double)an*aad>(double)ad*aan||((double)an*aad==(double)ad*aan&&tm<i+p)){
				y[0]=p;
				y[1]=i;
				tm=i+p;
				an=aan;
				ad=aad;
			}
		}
	}
	printf("%d %d\n",y[0],y[1]);
}