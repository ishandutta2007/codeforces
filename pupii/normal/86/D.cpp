#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il int gi(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
struct yyb{int l,r,L,i;}Q[200010];
il bool operator <(const yyb&a,const yyb&b){
	if(a.L^b.L)return a.L<b.L;
	if(a.L&1)return a.r<b.r;
	return a.r>b.r;
}
ll a[200010],ans[200010],tot[1000001];
int main(){
	int n=gi(),t=gi();
	for(int i=1;i<=n;++i)a[i]=gi();
	int qt=sqrt(t);
	for(int i=1;i<=t;++i)Q[i].l=gi(),Q[i].r=gi(),Q[i].L=Q[i].l/qt,Q[i].i=i;
	std::sort(Q+1,Q+t+1);
	int l=1,r=0;ll res=0;
	for(int i=1;i<=t;++i){
		while(Q[i].l<l)--l,res+=((tot[a[l]]++)<<1|1)*a[l];
		while(r<Q[i].r)++r,res+=((tot[a[r]]++)<<1|1)*a[r];
		while(Q[i].l>l)res-=((--tot[a[l]])<<1|1)*a[l],++l;
		while(r>Q[i].r)res-=((--tot[a[r]])<<1|1)*a[r],--r;
		ans[Q[i].i]=res;
	}
	for(int i=1;i<=t;++i)printf("%lld\n",ans[i]);
	return 0;////
}