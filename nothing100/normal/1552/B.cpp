#include<bits/stdc++.h>
using namespace std;
int t,n,a[50050][5];
int main(){
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		for (int i=1;i<=n;i++) 
		for (int j=0;j<5;j++) scanf("%d",&a[i][j]);
		int god=1;
		for (int i=2;i<=n;i++){
			int f=0;
			for (int j=0;j<5;j++)
			if (a[i][j]<a[god][j]) f++;
			if (f>=3) god=i;
		}
		for (int i=1;i<=n;i++)
		if (i!=god){
			int f=0;
			for (int j=0;j<5;j++)
			if (a[i][j]>a[god][j]) f++;
			if (f<3){
				god=-1;
				break;
			}
		}
		printf("%d\n",god);
	}
}