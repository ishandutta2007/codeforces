#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char c=getchar();int s=0;while(c<'0' or c>'9')c=getchar();
	while(c>='0' and c<='9')s=s*10+c-'0',c=getchar();return s;
}
const int N=105;
int T,n;
int a[N];
int tong[N];
int main(){
	cin>>T;
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		sort(a+1,a+n+1);
		int qz=0;
		for(int i=1;i<=n;i++){
			if(a[i]==a[1])qz++;
		}
		cout<<n-qz<<endl;
	}
	return 0;
}