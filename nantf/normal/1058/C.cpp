#include<bits/stdc++.h>
using namespace std;
int n,a[111],pre[111];
char s[111];
int main(){
	scanf("%d%s",&n,s);
	for(int i=1;i<=n;i++) a[i]=s[i-1]-48; 
	int sum1=0,sum2,sum3;
	for(int i=1;i<n;i++){
		sum1+=a[i];sum2=0;sum3=0;
		bool flag=true;
		for(int j=i+1;j<=n;j++){
			sum2+=a[j];sum3+=a[j];
			if(sum2>sum1) flag=false;
			else if(sum2==sum1) sum2=0;
		}
		if(flag && !sum2 && (!sum1 || (sum3%sum1==0 && sum3))) return puts("YES"),0;
	}
	puts("NO");
}