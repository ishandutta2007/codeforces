#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
const int INF=0x3f3f3f3f;
int n,Ans;
int c[200005],a[200005];
int v[200005];
int s[200005],t;
#define Luogu Judging_INF
int main(){
	scanf("%d",&n);
	F(i,1,n) scanf("%d",c+i);
	F(i,1,n) scanf("%d",a+i);
	F(i,1,n) if(!v[i]){
		t=0;
		int x=i;
		while(!v[x]){
			v[x]=i;
			s[++t]=x;
			x=a[x];
		}
		if(v[x]!=i) continue;
		int ok=0, S=INF;
		F(i,1,t){
			if(s[i]==x) ok=1;
			if(ok) S=min(S,c[s[i]]);
		}
		Ans+=S;
	}
	printf("%d",Ans);
	return 0;
}