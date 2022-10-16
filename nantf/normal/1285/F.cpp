#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,m,mu[maxn],pr[maxn],pl,stk[maxn],tp,cnt[maxn];
ll ans;
bool vis[maxn],in[maxn];
vector<int> dv[maxn];
inline int gcd(int x,int y){return y?gcd(y,x%y):x;}
int calc(int x){
	int s=0;
	FOR(i,0,(int)dv[x].size()-1) s+=mu[dv[x][i]]*cnt[dv[x][i]];
	return s;
}
void pop(){
	int x=stk[tp--];
	FOR(i,0,(int)dv[x].size()-1) cnt[dv[x][i]]--;
}
void push(int x){
	stk[++tp]=x;
	FOR(i,0,(int)dv[x].size()-1) cnt[dv[x][i]]++;
}
int main(){
	n=read();
	FOR(i,1,n){
		int x=read();
		m=max(m,x);
		in[x]=true;
	}
	FOR(i,1,m) FOR(j,1,m/i) in[i]|=in[i*j],dv[i*j].push_back(i);
	mu[1]=1;
	FOR(i,2,m){
		if(!vis[i]) mu[pr[++pl]=i]=-1;
		FOR(j,1,pl){
			if(i*pr[j]>m) break;
			vis[i*pr[j]]=true;
			if(i%pr[j]==0) break;
			mu[i*pr[j]]=-mu[i];
		}
	}
	ROF(i,m,1) if(in[i]){
		while(tp && calc(i)){
			if(gcd(i,stk[tp])==1) ans=max(ans,1ll*i*stk[tp]);
			pop();
		}
		push(i);
	}
	printf("%lld\n",ans);
}