#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	char c=getchar();int s=0;while(c<'0' or c>'9')c=getchar();
	while(c>='0' and c<='9')s=s*10+c-'0',c=getchar();return s;
}
const int N=10005; 
int T,n;
int a[N];
signed main(){
	cin>>T;
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		bool flag=0;
		if(n==1){
			puts("YES");
			continue;
		}
				for(int i=1;i<=n;i++){
			int gg=a[i]-(i-1);
			if(gg<0 and i!=n){flag=1;break;}
			if(i==n and a[i]<=a[i-1]){flag=1;break;}
			a[i+1]+=gg;
			a[i]=i-1;
		}
		if(!flag)puts("YES");
		else puts("NO");
		for(int i=1;i<=n;i++){
			a[i]=0;
		}
	}
	return 0;
}