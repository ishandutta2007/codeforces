#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define pb push_back
#define pii pair<int,int>
#define vi vector<pii> 
#define fi first
#define se second
using namespace std;
const int N=105;
char s[N][N],ans[N],ch[N];
int sum[N][26],sum2[26];
vi g[N];
int check(int l,int r){
	int res;
	memset(sum,0,sizeof sum);
	memset(sum2,0,sizeof sum2);
	printf("? %d %d\n",l,r);
	fflush(stdout);
	int len=r-l+1;
	if(len==1){
		scanf("%s",ch);
		ans[l]=ch[0];
		return (ch[0]-'a')<<1;
	}
	int cnt=len*(len+1)/2;
	while(cnt--){
		scanf("%s",ch);
		int clen=strlen(ch);
		rep(i,0,clen)++sum[clen][ch[i]-'a'];
	}
	int tot=0,cnt2=0,tot2=0;
	rep(i,0,26)if(sum[2][i]<sum[1][i]*2)tot+=i,++cnt2,++sum2[i];
	if(cnt2==1)++sum2[tot],tot<<=1;
	g[l].pb({r,tot});
	g[r].pb({l,tot});
	++l,--r;
	res=tot;
	tot2+=tot;
//	cout<<tot<<"tot\n";
	int pos=3;
	while(l+1<r){
		rep(i,0,26)sum[pos][i]-=sum2[i];
		tot=0,cnt2=0;
		rep(i,0,26)if(sum[pos][i]%pos)tot+=i,++cnt2,sum2[i]+=pos-1;
		if(cnt2==1)sum2[tot]+=pos-1,tot<<=1;
		g[l].pb({r,tot});
		g[r].pb({l,tot});
		tot2+=tot;
		++l,--r,++pos;
	}
	if(l==r){
	//	cout<<tot2<<"tot2\n";
		rep(i,0,26)tot2-=sum[1][i]*i;
		ans[l]=-tot2+'a';
	}
	else{
		rep(i,0,26)tot2-=sum[1][i]*i;
		tot2=-tot2;
		g[l].pb({r,tot2});
		g[r].pb({l,tot2});
	}
	return res;
}
void dfs(int u,int fa){
	for(pii oth:g[u]){
		int v=oth.fi,tot=oth.se;
		if(v==fa||ans[v])continue;
		ans[v]=tot-ans[u]+'a'+'a';
		dfs(v,u);
	}
}
int main(){
//	freopen("text.in","r",stdin);
	int n;
	scanf("%d",&n);
	if(n==1){
		check(1,1);
		fflush(stdout);
		printf("! %s",ans+1);
		return 0;
	}
	int mid=n/2;
	check(1,1);
	check(1,n);
	check(2,n);
	rep(i,1,n+1){
		if(ans[i])dfs(i,-1);
	}
	printf("! %s",ans+1);
}
/*
4

aa
a
a

a
b
c
ab
bc
abc

aabc
aab
abc
aa
ab
bc
a
a
b
c
*/