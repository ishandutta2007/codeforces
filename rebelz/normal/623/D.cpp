#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef long double ld;
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

int n;
ld now,ans;
ld a[105],b[105],cnt[105];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint()*0.01;
	for(int i=1;i<=n;i++){
		now+=log(a[i]);
		cnt[i]++,ans++;
		b[i]=log(1-pow(1-a[i],cnt[i]+1))-log(1-pow(1-a[i],cnt[i]));
	}
	for(int i=1;i<=300000;i++){
		ans+=1-exp(now);
		int x=max_element(b+1,b+n+1)-b;
		now+=b[x],cnt[x]++;
		b[x]=log(1-pow(1-a[x],cnt[x]+1))-log(1-pow(1-a[x],cnt[x]));
	}
	printf("%.10Lf\n",ans);
	return 0;
}