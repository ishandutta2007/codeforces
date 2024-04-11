#include<bits/stdc++.h>
using namespace std;
int n,q,num,f[2][100010];
int main(){
	scanf("%d%d",&n,&q);
	for (int i=0;i<q;i++){
		int o,p,t;
		scanf("%d%d",&o,&p);
		o--;
		if (f[o][p]==1) t=-1;
		else t=1;
		for (int j=-1;j<2;j++){
			if (p+j>=1&&p+j<=n&&f[o^1][p+j]==1) num+=t;
		}
		f[o][p]^=1;
		if (num) printf("No\n");
		else printf("Yes\n");
	}
}