#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char c=getchar();int s=0;while(c<'0' or c>'9')c=getchar();
	while(c>='0' and c<='9')s=s*10+c-'0',c=getchar();return s;
}
const int N=1000;
int T,n;
int a[N];
int f[N][N];
int main(){
	T=read();
	for(int i=1;i<=50;i++){
		for(int k=i;k<=50;k++){
			int aa=i;int gg=0;
			while(1){
				if(aa*2>=k)break;
				gg++;
				aa*=2;
			}
			f[i][k]=f[k][i]=gg;
		}
	}
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		int ans=0;
		for(int i=1;i<n;i++){
			int hh=min(a[i+1],a[i]);
			int cha=max(a[i+1],a[i]);
			ans+=f[hh][cha];
		}
		cout<<ans<<endl;
	}
	return 0;
}