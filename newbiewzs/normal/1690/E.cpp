#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int T,n,k,a[N],tong[N];
int s[N],f[N];
char c[N];
int read(){
	
}
signed main(){
//	freopen("data.in","r",stdin);
	cin>>T;
	while(T--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		int summ=0;
		for(int i=1;i<=n;i++){
			summ+=a[i]/k;
			a[i]%=k;
			tong[a[i]]++;
		}
		int suf=0;
		for(int i=1;i<=k/2;i++){
			if(k%2==0 && i==k/2){
				summ+=(tong[k/2]+suf)/2;
				continue;
			} 
			suf+=tong[k-i];
			int tmp=min(tong[i],suf);
			summ+=tmp;
			suf-=tmp;
		}
		if(k%2==1)summ+=suf/2;
		cout<<summ<<'\n';
		for(int i=0;i<=k;i++)tong[i]=0;
	}
	return 0;
}