#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int n,L;
struct fuck{ll t,a,b,s[2];}s[200010];
bool fk[2][2000010];
int A[2000010],mn[2000010];
ll div_floor(ll x,ll y){return(x-(x%y+y)%y)/y;}
ll div_ceil(ll x,ll y){return(x+(y-x%y)%y)/y;}
void work(bool o){
	ll l=0,r=L;
	for(int i=1;i<=n;++i){
		ll x=s[i].b-s[i-1].b,y=s[i].s[o]-s[i-1].s[o],z=s[i].a-s[i-1].a;
		if(x>0)l=std::max(l,div_ceil(y-z,x)),r=std::min(r,div_floor(y,x));
		else if(x<0)l=std::max(l,div_ceil(y,x)),r=std::min(r,div_floor(y-z,x));
		else if(y<0||y>z)puts("NO"),exit(0);
	}
	if(l>r)puts("NO"),exit(0);
	ll SL=l;
	memset(A,-1,sizeof A);
	A[0]=0;A[L]=SL;
	for(int i=1;i<=n;++i)A[s[i].a]=s[i].s[o]-SL*(s[i].b);
	mn[L]=A[L];for(int i=L-1;~i;--i)mn[i]=std::min(A[i]==-1?L:A[i],mn[i+1]);
	for(int i=1;i<=L;++i)if(A[i]==-1)A[i]=std::min(mn[i],A[i-1]+1);
	for(int i=1;i<=L;++i)fk[o][i]=A[i]!=A[i-1];
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	n=gi(),L=gi();
	ll t,x,y;
	for(int i=1;i<=n;++i){
		t=gi(),x=gi(),y=gi();if(x+y+t&1)return puts("NO"),0;
		s[i].t=t,s[i].a=s[i].t%L,s[i].b=s[i].t/L,s[i].s[0]=(x+y+t)/2,s[i].s[1]=(x-y+t)/2;
	}
	s[++n]={0,L,-1};s[n].s[0]=s[n].s[1]=0;
	std::sort(s+1,s+n+1,[](fuck a,fuck b){return a.a<b.a;});
	work(0),work(1);
	for(int i=1;i<=L;++i)
		if(fk[0][i])putchar(fk[1][i]?'R':'U');
		else putchar(fk[1][i]?'D':'L');
	return 0;
}