#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll n,m,s,t;
ll g[100005];
map<ll,int> d[100005];

int ask(ll x){
	if(g[x]!=-1) return g[x];
	ll tmp=x;
	for(int i=n;i>=1;i--){
		if(x<m) x=(x+i)%n;
		else x=(x-i+n)%n;
	}
	return g[tmp]=x;
}

int work(ll x,ll k){
	if(k==0) return x;
	if(k==1) return ask(x);
	if(d[x].count(k)) return d[x][k];
	return d[x][k]=work(work(x,k/2),k-k/2);
}

int main(){
	n=readint(); m=readint(); s=readint()-1; t=readint();
	while(t%n!=0){
		if(s<m) s=(s+t%n)%n;
		else s=(s-t%n+n)%n;
		t--;
	}
	memset(g,-1,sizeof(g));
	printf("%d\n",work(s,t/n)+1);
	return 0;
}