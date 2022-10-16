#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PII;
const int maxn=1111111,mod=998244353;
const ll INF=1e18;
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
inline int qmo(int x){return x+(x>>31?mod:0);}
int n,k=1;
ll b=0,c,a[maxn],ans[maxn],d[maxn];
set<PII> s;
bool in[maxn];
inline bool check(ll x){
	set<PII>::iterator it=s.lower_bound(MP(x,INF*9));
	if(it!=s.begin()){
		it--;
//		printf("check,it=%lld,%lld,x=%lld\n",it->first,it->second,x);
		return it->second>=x;
	}
	else return false;
}
int main(){
	n=read();c=read();
	FOR(i,1,n-2) a[i]=read();
	s.insert(MP(0,INF));
	FOR(i,1,n-2){
		if(k==1){
			set<PII>::iterator it=s.lower_bound(MP(a[i]-b,INF*9));
			if(it!=s.begin()){
				it--;
				if(it->second+b>=a[i]){
					s.clear();
					k=1;b=0;
					s.insert(MP(0,a[i]));
					in[i+1]=true;
//					printf("set %d\n",i+1);
				}
				else{
					if(it!=s.end()) it++;
					s.erase(it,s.end());
					if(!check(-k*b)) s.insert(MP(-k*b,-k*b));
					k*=-1;
					b=a[i]-b;
				}
			}
			else return puts("NO"),0;
		}
		else{
			set<PII>::iterator it=s.lower_bound(MP(b-a[i],INF*9));
//			printf("find %d\n",b-a[i]);
			if(it!=s.begin()){
				it--;
				if(b-it->second<=a[i]){
					s.clear();
					k=1;b=0;
					s.insert(MP(0,a[i]));
					in[i+1]=true;
//					printf("set %d\n",i+1);
				}
				else{
					it++;
					if(it==s.end()) return puts("NO"),0;
					s.erase(s.begin(),it);
					if(!check(-k*b)) s.insert(MP(-k*b,-k*b));
					k*=-1;
					b=a[i]-b;
				}
			}
			else{
				if(!check(-k*b)) s.insert(MP(-k*b,-k*b));
				k*=-1;
				b=a[i]-b;
			}
		}
		if(s.empty()) return puts("NO"),0;
		if(k==1) d[i+2]=s.begin()->first+b;
		else d[i+2]=b-s.rbegin()->second;
//		in[i+2]=check(k*(a[i]-b));
//		printf("try to insert %lld\n",k*(a[i]-b));
/*		printf("after %d\n",i);
		for(set<PII>::iterator it=s.begin();it!=s.end();it++) printf("[%lld,%lld],",it->first*k+b,it->second*k+b);
		puts("");
		for(set<PII>::iterator it=s.begin();it!=s.end();it++) printf("[%lld,%lld],",it->first,it->second);
		puts("");*/
	}
	puts("YES");
	ROF(i,n,2){
		if(in[i]) d[i]=a[i-1];//,printf("reset %d\n",i);
		if(d[i]!=a[i-2]) d[i-1]=a[i-2]-d[i];//,printf("assign %d\n",i-1);
//		printf("d[%d] is %lld\n",i,d[i]);
	}
	ll mn=0;
	FOR(i,2,n){
		if(d[i]==a[i-2] || d[i-1]==a[i-2]){
			if(ans[i-1]<ans[i-2]) ans[i]=ans[i-1]+d[i];
			else ans[i]=ans[i-1]-d[i];
		}
		else{
//			printf("%d in\n",i);
			if(ans[i-1]<ans[i-2]) ans[i]=ans[i-1]-d[i];
			else ans[i]=ans[i-1]+d[i];
		}
		mn=min(mn,ans[i]);
	}
	FOR(i,1,n) printf("%lld ",ans[i]-mn);
}