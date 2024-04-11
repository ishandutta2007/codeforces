#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=222222,mod=998244353;
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
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
int n,cnt[26],tp,vis[maxn],at[maxn];
PII stk[maxn];
char s[maxn];
void clear(){
	FOR(i,0,25) cnt[i]=0;
	FOR(i,1,n) stk[i]=MP(0,0),s[i]=vis[i]=0;
	tp=0;
}
inline int sum(){
	int s=0;
	FOR(i,0,25) s+=cnt[i];
	return s;
}
inline int mx(){
	int s=0;
	FOR(i,0,25) s=max(s,cnt[i]);
	return s;
}
void solve(){
	scanf("%s",s+1);
	n=strlen(s+1);
	FOR(i,1,n-1) if(s[i]==s[i+1]) cnt[s[i]-'a']++;
	int del=0,lst=0,rem=n;
	printf("%d\n",max((sum()+1)/2,mx())+1);
//	printf("sum=%d,mx=%d\n",sum(),mx());
	FOR(i,1,n){
		if((sum()+1)/2<=mx()) break;
		if(lst && s[i]==s[lst]){
			if(tp && stk[tp].first!=s[i]-'a'){
//				printf("i=%d,lst=%d\n",i,lst);
				printf("%d %d\n",at[stk[tp].second],lst-del);
				vis[stk[tp].second]++;
				vis[i]--;
				rem-=(lst-del)-at[stk[tp].second]+1;
				del+=(lst-del)-at[stk[tp].second]+1;
//				printf("become %d\n",rem);
				cnt[stk[tp].first]--;
				cnt[s[i]-'a']--;
				tp--;
			}
			else stk[++tp]=MP(s[i]-'a',i);//,printf("push %d\n",i);
		}
		at[i]=i-del;
		lst=i;
	}
	FOR(i,1,n) vis[i]+=vis[i-1];
	int id=0,lstc=-1;
	FOR(i,1,25) if(cnt[i]>cnt[id]) id=i;
	tp=del=lst=0;
//	printf("id=%d\n",id);
	FOR(i,1,n){
		if(vis[i]){del++;continue;}
		if(lst && s[i]-'a'==lstc){
//			printf("i=%d,lst=%d\n",i,lst);
			if(tp && stk[tp].first!=lstc && (stk[tp].first==id || lstc==id)){
				printf("%d %d\n",stk[tp].second,lst);
				del+=lst-stk[tp].second+1;
				rem-=lst-stk[tp].second+1;
				cnt[stk[tp].first]--;
				cnt[lstc]--;
				tp--;
			}
			else stk[++tp]=MP(lstc,i-del);//,printf("push %d\n",i-del);
		}
		lst=i-del;
		lstc=s[i]-'a';
	}
//	printf("tp=%d\n",tp);
	ROF(i,tp,1){
		printf("%d %d\n",stk[i].second,rem);
		rem=stk[i].second-1;
	}
	printf("1 %d\n",rem);
	clear();
}
int main(){
	int T=read();
	while(T--) solve();
}
// AHFDGBCEI