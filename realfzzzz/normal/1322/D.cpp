#include<bits/stdc++.h>
using namespace std;
inline int readint(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=2e3+5;
int n,m,l[maxn],s[maxn],c[maxn*2],f[maxn*2][maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	m=readint();
	for(int i=1;i<=n;i++) l[i]=readint();
	for(int i=1;i<=n;i++) s[i]=readint();
	for(int i=1;i<=n+m;i++) c[i]=readint();
	for(int i=1;i<=n+m;i++) for(int j=1;j<=n;j++) f[i][j]=-2e9;
	for(int i=n;i>0;i--){
		for(int j=n;j>0;j--)
			f[l[i]][j]=max(f[l[i]][j],f[l[i]][j-1]+c[l[i]]-s[i]);
		int s=n;
		for(int j=l[i];j<n+m;j++){
			for(int k=0;k<=s;k++)
				f[j+1][k/2]=max(f[j+1][k/2],f[j][k]+k/2*c[j+1]);
			s/=2;
		}
	}
	printf("%d\n",f[n+m][0]);
	return 0;
}