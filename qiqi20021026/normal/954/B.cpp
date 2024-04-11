#include<bits/stdc++.h>

using namespace std;

int n,f[1000][2];
char s[1000];
int main(){
	scanf("%d%s",&n,s+1);
	for (int i=1;i<=n;++i){
		f[i][0]=f[i-1][0]+1;
		f[i][1]=f[i-1][1]+1;
		if (!(i&1)){
			bool fl=1;
			for (int j=1;j<=i/2;++j)
				if (s[j]!=s[i/2+j]){fl=0; break;}
			if (fl) f[i][1]=min(f[i][1],f[i/2][0]+1);
		}
	}
	printf("%d\n",min(f[n][0],f[n][1]));
	
	return 0;
}