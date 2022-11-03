// It is made by XZZ
#include<cstdio>
#include<algorithm>
#define il inline
#define rg register
#define vd void
#define sta static
#define int long long
typedef long long ll;
using namespace std;
il int gi(){
	rg int x=0;rg char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int n,a[500111],t[500111],T[500111],ri,k;
il bool check(int mid){
	for(rg int i=1;i<=n;++i)T[i]=t[i];
	int tot=0;
	for(rg int i=1;i<=n;++i){
		T[i]+=T[i-1];
		int q=T[i];
		if(T[i]<mid)tot+=mid-q,T[i]+=mid-q,T[min(n,i+ri+ri)+1]-=mid-q;
		if(tot>k)return 0;
	}
	return 1;
}
main(){
	#ifdef xzz
	freopen("G.in","r",stdin);
	freopen("G.out","w",stdout);
	#endif
	n=gi(),ri=gi(),k=gi();
	for(rg int i=1;i<=n;++i)a[i]=gi(),t[max(1ll,i-ri)]+=a[i],t[min(n,i+ri)+1]-=a[i];
	int l=0,r=2e18,mid;
	while(l<r){
		mid=l+((r-l)>>1)+1;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	printf("%lld\n",l);
	return 0;
}