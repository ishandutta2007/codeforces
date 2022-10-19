#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mpr make_pair
#define fi first
#define se second
#define pq priority_queue<int>
#define pqll priority_queue<ll>
#define up(x,y) (x<(y)?x=(y):0)
#define dn(x,y) (x>(y)?x=(y):0)
#define ad(x,y) (x=(x+(y))%mod)
#define N 100009
using namespace std;

int n,cnt,a[N],len[N]; pair<pair<pair<pii,int>,int>,int> b[N];
char s1[N*10],s2[N*10]; vi ans[N];
int main(){
	scanf("%d",&n);
	int i,j;
	for (i=1; i<=n; i++){
		scanf("%s%s",s1+1,s2+1);
		int len1=strlen(s1+1),len2=strlen(s2+1);
		for (j=1; j<=len2; j++) a[i]|=1<<s2[j]-'a';
		for (; len1 && (a[i]>>s1[len1]-'a'&1); len1--);
		len[i]=len1;
		int t1=0,t2=0,t3=0;
		for (j=1; j<=len1; j++){
			t1=((ll)t1*97+s1[j]-'a'+66666)%1000000007;
			t2=((ll)t2*233+s1[j]-'a'+666666)%1000000009;
			t3=((ll)t3*2333+s1[j]-'a'+6666666)%998244353;	
		}
		b[i]=mpr(mpr(mpr(mpr(t1,t2),t3),a[i]),i);
	}
	sort(b+1,b+n+1);
	ans[cnt=1].pb(b[1].se);
	for (i=2; i<=n; i++){
		if (b[i].fi!=b[i-1].fi) cnt++;
		ans[cnt].pb(b[i].se);	
	}
	printf("%d\n",cnt);
	for (i=1; i<=cnt; i++){
		printf("%d",ans[i].size());
		for (int p:ans[i]) printf(" %d",p); puts("");
	}
	return 0;
}