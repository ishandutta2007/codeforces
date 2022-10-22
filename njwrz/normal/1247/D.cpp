#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll f[100005],n,m,tl[1005],pl,ssl[1005];
inline ll read(){
	ll X=0; bool flag=1; char ch=getchar();
	while(ch<'0'||ch>'9')
	 {if(ch=='-') flag=0; ch=getchar();}
	while(ch>='0'&&ch<='9')
	 {X=(X<<1)+(X<<3)+ch-'0'; ch=getchar();}
	if(flag) return X;
	return ~(X-1);
}
inline void write(ll X){
	if(X<0) {putchar('-'); X=~(X-1);}
	ll s[20],top=0;
	while(X) {s[++top]=X%10; X/=10;}
	if(!top) s[++top]=0;
	while(top) putchar(s[top--]+'0');
}
inline void dfs(ll ss,ll pp){
	f[ss]++;
	for(ll i=pp;i<=pl;i++){
		if((ll)(tl[i])*ss<=100000&&ssl[i]){
			dfs(tl[i]*ss,i);
		}
		if((ll)(tl[i])*ss>100000)break;
	}
}
void cl(){
	pl=0;
	bool f=1;
	while(f){
		ll s=1;pl++;
		for(ll i=1;i<=m;i++){
			s*=pl;if(s>100000){
				f=0;break;
			}
		}
		if(f)tl[pl]=s;
	}
	pl--;
	for(ll i=2;i<=pl;i++)ssl[i]=1;
	for(ll i=2;i<=pl;i++){
		if(ssl[i]){
			for(ll j=i*2;j<=pl;j+=i)ssl[j]=0;
		}
	}
}
int main(){
	n=read();m=read();
	ll x;
	ll ans=0;
	cl();
	for(ll i=1;i<=n;i++){
		x=read();
		ans+=f[x];
		ll t=x,s=1,l;bool f=1;
		for(ll j=2;j*j<=x&&f;j++){
			if(t%j==0){
				l=0;
				while(t%j==0){
					t/=j;l++;
				}
				while(l%m!=0){
					s*=j;l++;
					if(s>100000){
						f=0;break;
					}
				}
			}
		}
		if(t!=1&&f){
			l=1;
			while(l%m!=0){
				s*=t;l++;
				if(s>100000){
					f=0;break;
				}
			}
		}
		if(f)dfs(s,2);
	}
	write(ans);
	return 0;
}