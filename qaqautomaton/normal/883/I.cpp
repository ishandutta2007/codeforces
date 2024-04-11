#include<bits/stdc++.h>
inline int read(){
	int x=0,w=1;
	char ch=0;
	while (ch<'0' || ch>'9'){
		ch=getchar();
		if (ch=='-') w=-1;	
	}
	while (ch<='9' && ch>='0'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*w;
}
using namespace std;
typedef long long ll;
const int N=3e5+5;
int n,k,l,r,ans;
int a[N],dp[N],f[N];
inline bool chk(int x){
	memset(dp,0,sizeof(dp));	
	memset(f,0,sizeof(f));
	int L=0,R;
	dp[0]=f[0]=1;
	for (int i=1;i<=n;++i){
		f[i]=f[i-1];
		while (a[i]-a[L+1]>x) ++L;
		if (i-L<k) continue;
	 	R=i-k;
	 	if (L>0) dp[i]=(f[R]>f[L-1]);
		else dp[i]=1;
		f[i]+=dp[i];
		//if (x==20) printf("%d %d %d\n",i,L,R);
	}
	/*if (x==20){
		for (int i=1;i<=n;++i)
			printf("%d ",dp[i]);
		printf("\n");
	}*/
	return dp[n];	
}
int main(){
	n=read(),k=read();
	for (int i=1;i<=n;++i) a[i]=read();
	sort(a+1,a+n+1);
	l=0,r=1e9;
	while (l<=r){
		//printf("%d %d\n",l,r);
		int mid=(l+r)>>1;
		if (chk(mid)) r=mid-1,ans=mid;
		else l=mid+1;
	}
	//chk(20);
	printf("%d\n",ans);
	return 0;
}