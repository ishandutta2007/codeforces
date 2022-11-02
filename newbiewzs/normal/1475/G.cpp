#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int T,n,m,s;
int a[N],tong[N];
inline int read(){
	char c=getchar();int s=0;while(c<'0' or c>'9')c=getchar();
	while(c>='0' and c<='9')s=s*10+c-'0',c=getchar();return s;
}

int f[N];
signed main(){
	cin>>T;
	while(T--){
		memset(f,0,sizeof(f));
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		sort(a+1,a+n+1);
		int ma=0;
		for(int i=1;i<=n;i++){
			int xz=0;
			for(int k=1;k*k<=a[i];k++){
				if(a[i]%k==0){
					xz=max(xz,max(f[k],f[a[i]/k]));
				}
			}
			f[a[i]]=xz+1;
			ma=max(f[a[i]],ma);
		}
		cout<<n-ma<<endl;
	}
	return 0;
}