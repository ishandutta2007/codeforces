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

int n;
int a[100005],cnt[100005],num[100005];

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) cnt[i]=0;
		for(int i=1;i<=n;i++) a[i]=readint(),cnt[a[i]]++;
		int maxa=0;
		for(int i=1;i<=n;i++) chkmax(maxa,cnt[i]);
		if(maxa>(n+1)/2){
			printf("-1\n");
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++) num[i]=0;
		num[a[1]]++,num[a[n]]++;
		for(int i=2;i<=n;i++){
			if(a[i]==a[i-1]){
				ans++;
				num[a[i-1]]++,num[a[i]]++;
			}
		}
		int res=0,opt=0;
		for(int i=1;i<=n;i++) if(chkmax(res,num[i])) opt=i;
		for(int i=1;i<=n;i++) if(i!=opt) res-=num[i];
		printf("%d\n",ans+max(0,(res-2)/2));
	}
	return 0;
}