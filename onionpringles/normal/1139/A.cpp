#include <bits/stdc++.h>
using namespace std;
char b[1010101];
int main(){
	int n;scanf("%d",&n);
	scanf("%s",b);
	long long ans=0;
	for(int i=0;i<n;i++){
		if(b[i]-'0'&1);
		else{
			ans+=i+1;
		}
	}printf("%lld\n",ans);
}