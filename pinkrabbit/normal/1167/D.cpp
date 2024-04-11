#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define MN 500005
#define MM 600005
#define ll long long
#define mod 998244353
int n;
char s[MN];
int t[MN],stk[MN],tp;
int b[MN];
void S(int l,int r,int k){
	for(int i=l;i<=r;++i){
		b[i]=b[t[i]]=k;
		S(i+1,t[i]-1,k^1);
		i=t[i];
	}
}
int main(){
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;++i){
		if(s[i]=='(')stk[++tp]=i;
		else t[stk[tp]]=i,t[i]=stk[tp],--tp;
	}
	S(1,n,0);
	F(i,1,n)printf("%d",b[i]);
	return 0;
}