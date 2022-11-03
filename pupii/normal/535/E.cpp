#include<bits/stdc++.h>
#define il inline
#define vd void
#define ll long long
#define db long double
il int gi(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
std::set<std::pair<int,int> >M;
struct yyb{int x,y,i;db k,b;}s[300010],stk[300010];
il bool cmp_k(const yyb&a,const yyb&b){
	if(a.y!=b.y)return a.y<b.y;
	else return a.x>b.x;
}
il bool cmp_i(const yyb&a,const yyb&b){return a.i<b.i;}
int main(){
	int n=gi();
	for(int i=1;i<=n;++i)s[i].x=gi(),s[i].y=gi(),s[i].i=i,s[i].k=1000000000.0/s[i].y,s[i].b=1000000000.0/s[i].x;
	std::sort(s+1,s+n+1,cmp_k);
	int top=0;
	stk[++top]=(yyb){0,0,0,1e18,0};
	for(int i=1;i<=n;++i){
		if(s[i].y==s[i-1].y)continue;
		while(top>1&&stk[top].y!=stk[top-1].y&&(-(s[i].b-stk[top].b)/(s[i].k-stk[top].k)+1e-15<-(stk[top].b-stk[top-1].b)/(stk[top].k-stk[top-1].k))){
			
			--top;
		}
		stk[++top]=s[i];
	}
	std::sort(s+1,s+n+1,cmp_i);
	for(int i=1;i<=top;++i)M.insert(std::make_pair(stk[i].x,stk[i].y));
	for(int i=1;i<=n;++i)if(M.find(std::make_pair(s[i].x,s[i].y))!=M.end())printf("%d ",i);
	return 0;
}