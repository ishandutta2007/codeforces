#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	char c=getchar();int s=0;while(c<'0' or c>'9')c=getchar();
	while(c>='0' and c<='9')s=s*10+c-'0',c=getchar();return s;
}
const int N=1e4+5;
int T,n;
map<int,int>ma;
int ycl[N];
signed main(){
	T=read();
	for(int i=1;i<=10000;i++){
		int gg=i*i*i;
		ycl[i]=gg;
		ma[ycl[i]]=1;
	}
	while(T--){
		n=read();bool flag=0;
		for(int i=1;i<=10000;i++){
			if(ma[n-ycl[i]])flag=1;
		}
		if(flag)puts("YES");
		else puts("NO"); 
	}
	return 0;
}