#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
typedef long long LL;

int n,q;
char a[100011],b[100011];
int s[2][2];
LL Ans=0;

int main(){
	scanf("%d",&n);
	scanf("%s%s",a+1,b+1);
	F(i,1,n){
		if(a[i]=='0'&&b[i]=='0') Ans+=s[1][0]+s[1][1];
		if(a[i]=='0'&&b[i]=='1') Ans+=s[1][0];
		if(a[i]=='1'&&b[i]=='0') Ans+=s[0][0]+s[0][1];
		if(a[i]=='1'&&b[i]=='1') Ans+=s[0][0];
		s[a[i]-'0'][b[i]-'0']++;
	}
	printf("%I64d\n",Ans);
	return 0;
}