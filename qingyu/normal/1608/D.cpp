#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Mod=998244353;
int n,tot,num; ll inv[110000];
char s[110000];
int C(int n,int m){
	if (n<m) return 0;
	ll mul=1;
	for (int i=n-m+1;i<=n;i++) mul=mul*i%Mod;
	for (int i=1;i<=m;i++) mul=mul*inv[i]%Mod;
	return mul;
}
int main(){
	inv[1]=1; for (int i=2;i<=100000;i++) inv[i]=(Mod-Mod/i)*inv[Mod%i]%Mod;
	scanf("%d",&n); int mul=1,ok1=0,ok2=0;
	for (int i=1;i<=n;i++){
		scanf("%s",s);
		if (s[0]=='?') tot++;
		else
			if (s[0]=='W') num++;
			else num--;
		if (s[1]=='?') tot++;
		else
			if (s[1]=='W') num++;
			else num--;
		
		int c=0;
		if (s[0]!='B'&&s[1]!='W') c++,ok1++;
		if (s[0]!='W'&&s[1]!='B') c++,ok2++;
		mul=mul*c%Mod;
	}
	int x=-1;
	for (int i=0;i<=tot;i++)
		if (i-(tot-i)==num) x=i;
	if (x==-1){
		puts("0");
		return 0;
	}
//	int x=(num+tot)/2;
	int ans=(C(tot,x)-mul+Mod)%Mod;
	if (ok1==n) ans=(ans+1)%Mod;
	if (ok2==n) ans=(ans+1)%Mod;
	printf("%d\n",ans);
	return 0;
}