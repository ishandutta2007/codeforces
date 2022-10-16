#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010,sq=333;
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
int n,k,a[maxn];
vector<PII> d[maxn],tmp;
map<vector<PII>,int> cnt;
ll ans;
int main(){
	n=read();k=read();
	FOR(i,1,n) a[i]=read();
	FOR(i,1,n){
		int x=a[i];
		tmp.clear();
		FOR(j,2,sqrt(x)) if(x%j==0){
			int cnt=0;
			while(x%j==0) x/=j,cnt=(cnt+1)%k;
			if(cnt) d[i].push_back(MP(j,cnt)),tmp.push_back(MP(j,k-cnt));
		}
		if(x>1) d[i].push_back(MP(x,1)),tmp.push_back(MP(x,k-1));
		ans+=cnt[tmp];
		cnt[d[i]]++;
	}
	printf("%lld\n",ans);
}