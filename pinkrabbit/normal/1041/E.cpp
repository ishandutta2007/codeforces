#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
int n,q;
int a[300001],b[300001];
int vis[300001];
int main(){
	scanf("%d",&n);
	F(i,1,n-1) scanf("%d%d",a+i,b+i);
	F(i,1,n-1) if(b[i]!=n) return puts("NO"),0;
	sort(a+1,a+n);
	b[n]=n;
	F(i,1,n-1) b[i]=a[i];
	F(i,1,n-1){
		if(a[i]==a[i-1]){
			int u=-1;
			F(j,1,b[i]) if(!vis[j]) u=j;
			if(~u) b[i]=u, vis[u]=1;
			else return puts("NO"),0;
		}
		else vis[b[i]]=1;
	}
	puts("YES");
	F(i,1,n-1) printf("%d %d\n",b[i],b[i+1]);
	return 0;
}