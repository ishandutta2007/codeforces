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

int n,m=20,now;
int a[25][25],f[25],d[1100000],cnt[1100000],to[25];
char s[100005],t[100005];
vector<int> vec;

int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

int merge(int x,int y){
	int fx=getf(x),fy=getf(y);
	if(fx==fy) return 0;
	f[fx]=fy;
	return 1;
}

int main(){
	int T=readint();
	while(T--){
		n=readint();
		scanf("%s%s",s+1,t+1);
		for(int i=0;i<m;i++) for(int j=0;j<m;j++) a[i][j]=0;
		for(int i=1;i<=n;i++) a[s[i]-'a'][t[i]-'a']=1;
		for(int i=0;i<m;i++) to[i]=0;
		for(int i=0;i<m;i++) for(int j=0;j<m;j++) if(i!=j&&a[i][j]) to[i]|=1<<j;
		vec.clear();
		int num1=0,num2=0;
		for(int i=1;i<(1<<m);i++) cnt[i]=cnt[i>>1]+(i&1);
		for(int i=1;i<(1<<m);i++){
			bool fl=1;
			for(int j=0;j<m;j++) if(((i>>j)&1)&&cnt[(to[j]&i)]!=1) fl=0;
			if(fl) vec.pb(i);
		}
		for(int i=0;i<(1<<m);i++) d[i]=0;
		for(auto r:vec) d[r^((1<<m)-1)]=1;
		for(int i=0;i<m;i++) for(int j=0;j<(1<<m);j++) if(j&(1<<i)) d[j^(1<<i)]|=d[j];
		int ans=1<<30;
		for(int i=0;i<(1<<m);i++){
			if(i) cnt[i]=cnt[i>>1]+(i&1);
			if(!d[i]) chkmin(ans,cnt[i]);
		}
		for(int i=0;i<m;i++) f[i]=i;
		for(int i=0;i<m;i++) for(int j=0;j<m;j++) if(a[i][j]&&merge(i,j)) ans++;
		printf("%d\n",ans);
	}
	return 0;
}