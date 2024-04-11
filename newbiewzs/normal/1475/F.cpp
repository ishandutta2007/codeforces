#include<bits/stdc++.h>
using namespace std;
int T,n,m,s;
int a[1005][1005],b[1005][1005];
inline int read(){
	char c=getchar();int s=0;while(c<'0' or c>'9')c=getchar();
	while(c>='0' and c<='9')s=s*10+c-'0',c=getchar();return s;
}
char c[5000];
signed main(){
	cin>>T;
	while(T--){
		n=read();
		for(int i=1;i<=n;i++){
			scanf("%s",c+1);
			for(int k=1;k<=n;k++){
				a[i][k]=c[k]-'0';
			}
		}
		for(int i=1;i<=n;i++){
			scanf("%s",c+1);
			for(int k=1;k<=n;k++){
				b[i][k]=c[k]-'0';
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i][1]!=b[i][1]){
				for(int k=1;k<=n;k++){
					a[i][k]^=1;
				}
			}
		}
		bool flag=0;
		for(int i=2;i<=n;i++){
			int hh;
			if(a[1][i]==b[1][i])hh=1;
			else hh=-1;
			for(int k=2;k<=n;k++){
				if(a[k][i]==b[k][i] and hh==-1)flag=1;
				if(a[k][i]!=b[k][i] and hh==1)flag=1;
			}
		}
		if(flag)puts("NO");
		else puts("YES");
	}
	return 0;
}