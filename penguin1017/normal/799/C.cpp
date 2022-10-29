#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&(-x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
using namespace std;
const int N=1e5+9;
const ll mod=998244353;
int p[N],maxn[N],maxn2[N],b[N],op[N];
char s[2]; 
int sum[N];
void upd(int &a,int b){
	if(a<b)a=b;
}
void Set(int p,int val){
	for(int i=p;i<N;i+=lb(i))upd(sum[i],val);
}
int Get(int p){
	int res=0;
	for(int i=p;i;i^=lb(i))upd(res,sum[i]);
	return res;
}
int main(){
	int n,c,d;
	scanf("%d%d%d",&n,&c,&d);
	rep(i,1,n+1){
		scanf("%d%d",&b[i],&p[i]);
		scanf("%s",s);
		if(s[0]=='C'){
			upd(maxn[p[i]],b[i]);
			op[i]=0;
		}
		else{
			upd(maxn2[p[i]],b[i]);
			op[i]=1;
		}
	}
	rep(i,1,N)upd(maxn[i],maxn[i-1]),upd(maxn2[i],maxn2[i-1]);
	int ans=0;
	if(maxn[c]&&maxn2[d])ans=maxn[c]+maxn2[d];
	rep(i,1,n+1){
		if(op[i])continue;
		if(p[i]>=c)continue;
		int x=Get(c-p[i]);
	//cout<<p[i]<<' '<<i<<"ok\n";
		if(x)upd(ans,x+b[i]);
		Set(p[i],b[i]);
	} 
	memset(sum,0,sizeof sum);
	rep(i,1,n+1){
		if(!op[i])continue;
		if(p[i]>=d)continue;
		int x=Get(d-p[i]);
		if(x)upd(ans,x+b[i]);
		Set(p[i],b[i]);
	}
	cout<<ans;
}