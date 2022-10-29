#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define fi first
#define se second
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
#define inf 0x3f3f3f3f

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef vector<int> vi;

const int N=4e5+5;
char str1[N],str2[N];
int n,m,pre[N];
vector<int> vec[30];

struct Bit {
	int sum[N];
	int lowbit(int x) {return x&(-x);}
	void update(int x,int a) {
		if (!x) return;
		while (x<=n) {
			sum[x]+=a;
			x+=lowbit(x);
		}
	}
	int query(int x) {
		int res=0;
		while (x) {
			res+=sum[x];
			x-=lowbit(x);
		}
		return res;
	}
	void change(int x,int y,int a) {
		update(x,a);
		update(y+1,-a);	
	}
}Bit;

int main() {
	scanf("%d%s",&n,str1+1);
	memcpy(str2,str1,sizeof(str2));
	reverse(str2+1,str2+1+n);// str2 goal
	rep(i,1,n+1) {
		int x=str1[i]-'a';
		vec[x].pb(i);	
	}
	per(i,n+1,1) {
		int x=str2[i]-'a';
		pre[i]=vec[x].back();
		vec[x].pop_back();
	}
	//rep(i,1,n+1) printf("%d ",pre[i]);
	ll ans=0;
	per(i,n+1,1) {
		int now=pre[i]+Bit.query(pre[i]);
		//bug(i),bug(pre[i]),debug(now);
		ans+=i-now;
		Bit.change(pre[i],n,-1);
	}
	printf("%lld\n",ans);
	return 0;	
}