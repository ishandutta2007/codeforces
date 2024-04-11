#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;
inline int read(){
	int v=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0' && c<='9'){
		v=v*10+c-'0';
		c=getchar();
	}
	return v*f;
}
const int Maxn=1000005;
int n,a[Maxn];
LL S[Maxn];
struct P{
	LL x,y;
	P(LL _x=0,LL _y=0){
		x=_x,y=_y;
	}
	P operator +(P p){
		return P(x+p.x,y+p.y);
	}
	P operator -(P p){
		return P(x-p.x,y-p.y);
	}
	LL det(P p){
		return x*p.y-y*p.x;
	}
};
vector<P> V;
int Nxt[Maxn];
double Ans[Maxn];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		a[i]=read();
		S[i]=S[i-1]+a[i];
	}
	for (int i=n;i>=0;i--){
		P tmp(i,S[i]);
		while (V.size()>=2 && (tmp-V[V.size()-1]).det(V[V.size()-2]-V[V.size()-1])>=0){
			V.pop_back();
		}
		if (i!=n){
			Nxt[i+1]=V[V.size()-1].x;
		}
		V.pb(tmp);
		
	}
	for (int i=1;i<=n;){
		int j=Nxt[i];
		LL S=0;
		for (int k=i;k<=j;k++){
			S+=a[k];
		}
		double tmp=(double)S/(j-i+1);
		for (int k=i;k<=j;k++){
			Ans[k]=tmp;
		}
		i=j+1;
	}
	for (int i=1;i<=n;i++){
		printf("%.10lf\n",Ans[i]);
	}
	return 0;
}