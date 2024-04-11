#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+55;
int f[N],n,a[N],b[N],c[N],T;
signed main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%lld",&c[i]);
			c[i]--;
		}
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(int i=1;i<=n;i++){
			scanf("%lld",&b[i]);
		}
		f[1]=n;
		int ans=0;
		for(int i=2;i<=n;i++){
			if(a[i]==b[i]){
				f[i]=max(f[i],c[i]+2);
			}
			else{
				f[i]=max(f[i],c[i]+abs(a[i]-b[i])+2);
				if(a[i-1]==b[i-1]){
					if(i-1>1)f[i]=max(f[i],c[i]+c[i-1]-abs(a[i]-b[i])+4);
				}
				else{
					if(i-2>=2)f[i]=max(f[i],f[i-2]+c[i]+c[i-1]-abs(a[i]-b[i])+4-abs(a[i-1]-b[i-1]));
					if(i>=3)f[i]=max(f[i],c[i]+c[i-1]-abs(a[i]-b[i])+4+abs(a[i-1]-b[i-1]));
				}
			}
		//	cout<<f[i]<<endl;
			ans=max(ans,f[i]);
		}
		for(int i=1;i<=n;i++)f[i]=0;
		cout<<ans<<endl;
	} 
	return 0;
}