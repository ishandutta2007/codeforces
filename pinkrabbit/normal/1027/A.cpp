#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define Luogu Judge
int n; char s[170];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int ok=1;
		scanf("%d%s",&n,s+1);
		F(i,1,n/2) if(abs(s[i]-s[n-i+1])!=0&&abs(s[i]-s[n-i+1])!=2) ok=0;
		puts(ok?"YES":"NO");
	}
	return 0;
}