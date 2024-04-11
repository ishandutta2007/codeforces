#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	char c=getchar();int s=0;while(c<'0' or c>'9')c=getchar();
	while(c>='0' and c<='9')s=s*10+c-'0',c=getchar();return s; 
}
const int N=1e5+55;
int T;
int A,B,n;
struct node{
	int a,b,f;
}c[N];
int cmp(node x,node y){
	return x.a<y.a;
}
signed main(){
	T=read();
	while(T--){
		A=read();B=read();n=read();
		int gg=0;
		for(int i=1;i<=n;i++){
			c[i].a=read();
		}
		int ans=0;bool flag=0;
		for(int i=1;i<=n;i++){
			c[i].b=read();
			c[i].f=(c[i].b%A);
			
		}
		sort(c+1,c+n+1,cmp);
		for(int i=1;i<=n;i++){
			gg=ceil((1.0*c[i].b/A));
			ans+=gg*c[i].a;
			if(ans>=B){
				if(i<n)flag=1;
				else{
					if(ans-c[i].a<B)flag=0;
					else flag=1;
				}
			}
		}
		if(flag)puts("NO");
		else puts("YES");
	} 
	return 0;
}