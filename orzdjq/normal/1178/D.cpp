#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;
int p[1033];
void _init(){
	p[0]=p[1]=false;
	for (int i=2;i<1033;i++) p[i]=1;
	for (int i=2;i<1033;i++){
		if (p[i]){
			for (int j=i+i;j<1033;j+=i) p[j]=0;
		}
	}
}
int main(){
	_init();
	int n;
	cin>>n;
	if (p[n]){
		printf("%d\n",n);
		for (int i=1;i<=n-1;i++){
			printf("%d %d\n",i,i+1);
		}
		printf("%d %d\n",1,n);
		return 0;
	}
	for (int i=n;;i++){
		if (p[i]){
			printf("%d\n",i);
			for (int i=1;i<=n-1;i++){
				printf("%d %d\n",i,i+1);
			}
			printf("%d %d\n",1,n);
			int t=i-n;
			for (int j=0;j<t/2;j++){
				int v1=j*4+1;
				printf("%d %d\n",v1,v1+2);
				printf("%d %d\n",v1+1,v1+3);
			}
			if (t%2==1){
				int vv=t/2*4+1;
				printf("%d %d\n",vv,vv+2);
			}
			return 0;
		}
	}
}