#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int n,k,s,y[1000010];
char S[1000010];
struct data{double x;int y;}f[1000010];
bool operator<(data a,data b){
	if(fabs(a.x-b.x)>1e-8)return a.x<b.x;
	else return a.y<b.y;
}
data operator+(data a,data b){return{a.x+b.x,a.y+b.y};}
int solve(){
	double l=-1,r=1e6+1,mid;
	data _;
	while(r-l>1e-6){
		mid=(l+r)*0.5;
		for(int i=1;i<=n;++i){
			f[i]=f[i-1]+data{y[i],0};
			if(i>=s)f[i]=std::min(f[i],f[i-s]+data{mid,1});
		}
		if(f[n].y>k)l=mid;else _=f[n],r=mid;
	}
	return int(_.x-k*l+0.5);
}
int main(){
	n=gi(),k=gi(),s=gi();scanf("%s",S+1);
	if(1ll*k*s>=n)return puts("0"),0;
	for(int i=1;i<=n;++i)y[i]=!!islower(S[i]);
	int ans=solve();
	for(int i=1;i<=n;++i)y[i]=!!isupper(S[i]);
	printf("%d\n",std::min(solve(),ans));
	return 0;
}