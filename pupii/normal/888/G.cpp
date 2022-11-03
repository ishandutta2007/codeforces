#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int a[200010];
int ch[6000010][2],num[200010],cnt=1;
void insert(int num){
	int x=1;
	for(int i=29,o;~i;--i){
		o=(num>>i)&1;
		if(!ch[x][o])ch[x][o]=++cnt;
		x=ch[x][o];
	}
}
ll ans;
int start[6000010],end[6000010],DFN;
void pdfs(int x,int dep,int NUM){
	if(!x)return;
	start[x]=DFN+1;
	if(dep==-1)num[++DFN]=NUM;
	else pdfs(ch[x][0],dep-1,NUM<<1),pdfs(ch[x][1],dep-1,NUM<<1|1);
	end[x]=DFN;
}
int query(int x,int dep,int y){
	if(dep==-1)return 0;
	int o=(y>>dep)&1;
	if(ch[x][o])return query(ch[x][o],dep-1,y);
	else return(1<<dep)+query(ch[x][!o],dep-1,y);
}
void dfs(int x,int dep){
	if(!x||dep==-1)return;
	if(ch[x][0]&&ch[x][1]){
		int L1=start[ch[x][0]],R1=end[ch[x][0]];
		int L2=start[ch[x][1]],R2=end[ch[x][1]];
		ans+=1<<dep;int res=INT_MAX;
		if(R1-L1<R2-L2)for(int i=L1;i<=R1;++i)res=std::min(res,query(ch[x][1],dep-1,num[i]));
		else for(int i=L2;i<=R2;++i)res=std::min(res,query(ch[x][0],dep-1,num[i]));
		ans+=res;
	}
	dfs(ch[x][0],dep-1);dfs(ch[x][1],dep-1);
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi();
	for(int i=1;i<=n;++i)a[i]=gi(),insert(a[i]);
	pdfs(1,29,0);dfs(1,29);
	printf("%lld\n",ans);
	return 0;
}