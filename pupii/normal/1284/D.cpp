#include<bits/stdc++.h>
typedef long long ll;
#define db long double
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int LA[100010],LB[100010],RA[100010],RB[100010];
struct fk{int a,b,c,d,o;}s[200010],_s[200010];
bool operator<(const fk&a,const fk&b){
	if(a.b^b.b)return a.b>b.b;
	return a.o<b.o;
}
int n,N,u[400010];
void divide(int l,int r){
	if(l==r)return;
	int mid=l+r>>1;
	divide(l,mid),divide(mid+1,r);
	int pl=l,pr=mid+1,p=l-1,MX=0,MN=1e9;
	while(pl<=mid||pr<=r){
		if(pl<=mid&&(pr>r||s[pl]<s[pr])){
			_s[++p]=s[pl++];
			if(_s[p].o==0)MX=std::max(MX,_s[p].c),MN=std::min(MN,_s[p].d);
		}else{
			_s[++p]=s[pr++];
			if(_s[p].o==1&&(MX>_s[p].c||MN<_s[p].d))
				puts("NO"),exit(0);
		}
	}
	for(int i=l;i<=r;++i)s[i]=_s[i];
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	n=gi();
	for(int i=1;i<=n;++i)LA[i]=u[++N]=gi(),RA[i]=u[++N]=gi(),LB[i]=u[++N]=gi(),RB[i]=u[++N]=gi();
	std::sort(u+1,u+N+1);
	for(int i=1;i<=n;++i)LA[i]=std::lower_bound(u+1,u+N+1,LA[i])-u-1;
	for(int i=1;i<=n;++i)RA[i]=std::lower_bound(u+1,u+N+1,RA[i])-u-1;
	for(int i=1;i<=n;++i)LB[i]=std::lower_bound(u+1,u+N+1,LB[i])-u-1;
	for(int i=1;i<=n;++i)RB[i]=std::lower_bound(u+1,u+N+1,RB[i])-u-1;
	// SORT lA<=RA,SORT2 ra>=LA, BIT lB>RB || rB<LB
	//WSSB*3
	for(int i=1;i<=n;++i)s[i]={LA[i],RA[i],LB[i],RB[i],0};
	for(int i=1;i<=n;++i)s[i+n]={RA[i],LA[i],RB[i],LB[i],1};
	std::sort(s+1,s+n*2+1,[](fk a,fk b){if(a.a^b.a)return a.a<b.a;return a.o<b.o;});
	divide(1,n+n);
	for(int i=1;i<=n;++i)s[i]={LB[i],RB[i],LA[i],RA[i],0};
	for(int i=1;i<=n;++i)s[i+n]={RB[i],LB[i],RA[i],LA[i],1};
	std::sort(s+1,s+n*2+1,[](fk a,fk b){if(a.a^b.a)return a.a<b.a;return a.o<b.o;});
	divide(1,n+n);
	puts("YES");
	return 0;
}