#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=998244353;
int n,m,a,b;
int maxa[25],mina[25],rnk[30],p[25],num[25];
bool d[1100000];
char ch[25],s[5005];

ll mod(ll x){return x>=cys?x-cys:x;}

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

int main(){
	n=readint(); a=readint(); b=readint();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		if(!rnk[s[i]-'a']) ch[++m]=s[i],rnk[s[i]-'a']=m,mina[m]=i;
		maxa[rnk[s[i]-'a']]=i;
		num[rnk[s[i]-'a']]++;
	}
	for(int i=1;i<=m;i++) p[i]=i;
	sort(p+1,p+m+1,[&](int x,int y){return maxa[x]<maxa[y];});
	d[0]=1;
	for(int i=1;i<(1<<m);i++){
		int mn=1<<30,mx=0,sum=0,can=0;
		for(int j=0;j<m;j++){
			if((i>>j)&1){
				chkmin(mn,mina[j+1]);
				chkmax(mx,maxa[j+1]);
				sum+=num[j+1];
				can|=d[i^(1<<j)];
			}
		}
		if(can&&(mx-mn+1)*a<=sum*b) d[i]=1;
		int t=0;
		for(int j=1;j<=m;j++){
			if((i>>(p[j]-1))&1){
				t^=1<<(p[j]-1);
				d[i]|=d[t]&d[i^t];
			}
		}
	}
	vector<int> ans(0);
	for(int i=1;i<=m;i++) if(d[((1<<m)-1)^(1<<(i-1))]) ans.pb(i);
	sort(ans.begin(),ans.end(),[&](int x,int y){return ch[x]<ch[y];});
	printf("%d ",ans.size());
	for(auto r:ans) printf("%c ",ch[r]);
	printf("\n");
	return 0;
}