#include<bits/stdc++.h>
using namespace std;

int n,s,a[200];

int main(){
	cin>>n>>s;
	for(int i=1;i<=n;i++){
		int x,y;cin>>x>>y;
		a[i]=x*60+y;
	}
	for(int i=0;;i++){
		int fg=1;
		for(int j=1;j<=n;j++){
			if(a[j]>i&&a[j]-i<=s||a[j]<i&&i-a[j]-1<s||i==a[j])fg=0;
		}
		if(fg){
			printf("%d %d\n",i/60,i%60);return 0;
		}
	}
	return 0;
}