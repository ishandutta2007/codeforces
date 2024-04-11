// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=998244353;
int n,x,cnt;
int ch[4500005][2],siz[4500005];
ll pw[150005];

void insert(int x){
	int p=1;
	for(int i=29;i>=0;i--){
		if(!ch[p][(x>>i)&1]) ch[p][(x>>i)&1]=++cnt;
		p=ch[p][(x>>i)&1];
		siz[p]++;
	}
}

ll dp(int a,int b,int dep){
//	cout<<"dp "<<a<<' '<<b<<' '<<dep<<endl;
	if(!a||!b) return 0;
	if(dep<0){
		if(a==b) return pw[siz[a]]-1;
		else return (pw[siz[a]]-1)*(pw[siz[b]]-1)%cys;
	}
	int t=(x>>dep)&1;
	if(!t) return (dp(ch[a][0],ch[b][0],dep-1)+dp(ch[a][1],ch[b][1],dep-1))%cys;
	else{
		if(a==b){
			ll ret=dp(ch[a][0],ch[b][1],dep-1);
			ret=(ret+pw[siz[ch[a][0]]]-1+pw[siz[ch[a][1]]]-1)%cys;
			return ret;
		}
		ll t1=dp(ch[a][0],ch[b][1],dep-1);
		ll t2=dp(ch[a][1],ch[b][0],dep-1);
		ll ret=((t1+1)*(t2+1)-1);
		ret=(ret+(pw[siz[ch[a][0]]]-1)*(pw[siz[ch[b][0]]]-1));
		ret=(ret+(pw[siz[ch[a][1]]]-1)*(pw[siz[ch[b][1]]]-1));
		ret=(ret+t1*(pw[siz[ch[a][1]]]-1));
		ret=(ret+t2*(pw[siz[ch[a][0]]]-1));
		ret=(ret+t1*(pw[siz[ch[b][0]]]-1));
		ret=(ret+t2*(pw[siz[ch[b][1]]]-1));
		return ret%cys;
	}
}

int main(){
	n=readint(); x=readint();
	cnt=1;
	for(int i=1;i<=n;i++) insert(readint());
	pw[0]=1;
	for(int i=1;i<=n;i++) pw[i]=pw[i-1]*2%cys;
	printf("%lld\n",dp(1,1,29));
	return 0;
}