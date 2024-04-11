#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	mutable ll fi,se;
	bool operator<(const node c)const{
		if(fi==c.fi) return se<c.se;
		return fi<c.fi;
	}
};

ll n,cnt,cnt1,cnt2;
pll s[300005];
ll t[300005],a[300005],a1[300005],a2[300005];
ll ansx[1500005],ansy[1500005],ansd[1500005];

void move(ll x,ll y,ll d){
	ansx[++cnt]=x,ansy[cnt]=y,ansd[cnt]=d;
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) s[i]=mp(readint(),i);
	sort(s+1,s+n+1);
	for(int i=1;i<=n;i++) t[i]=readint();
	sort(t+1,t+n+1);
	for(int i=1;i<=n;i++) a[i]=t[i]-s[i].fi;
	ll now=0;
	for(int i=1;i<=n;i++) if(now+a[i]<0) return printf("NO\n"),0; else now+=a[i];
	if(now!=0) return printf("NO\n"),0;
	for(int i=1;i<=n;i++) if(a[i]>0) a1[++cnt1]=i; else a2[++cnt2]=i;
	now=1;
	for(int i=1;i<=cnt1;i++){
		while(a[a1[i]]){
			while(a[a2[now]]==0) now++;
			if(a[a1[i]]<-a[a2[now]]) move(s[a1[i]].se,s[a2[now]].se,a[a1[i]]),a[a2[now]]+=a[a1[i]],a[a1[i]]=0;
			else move(s[a1[i]].se,s[a2[now]].se,-a[a2[now]]),a[a1[i]]+=a[a2[now]],a[a2[now]]=0,now++;
		}
	}
	for(int i=1;i<=n;i++) assert(a[i]==0);
	cout<<"YES\n"<<cnt<<endl;
	for(int i=1;i<=cnt;i++) cout<<ansx[i]<<' '<<ansy[i]<<' '<<ansd[i]<<endl;
	return 0;
}