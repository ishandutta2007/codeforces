#include<bits/stdc++.h>
using namespace std;
const int N=1e5+55;
int T,n;
char a[N];
int b[N];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		scanf("%s",a+1);
		b[1]=1;cout<<1;
		for(int i=2;i<=n;i++){
			if(a[i-1]+b[i-1]!=a[i]+1){
				b[i]=1;
			}
			else{
				b[i]=0;
			}
			printf("%d",b[i]);
		}
		puts("");
	}
	return 0;
}