#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll f[1000005],d[1000005];
char s[1000000];
int main(){
	scanf("%s",s);
	ll a,b;
	cin>>a>>b;
	ll l=strlen(s);
	ll t=0;
	for(int i=0;i<l;i++){
		t=(t*10+s[i]-'0')%a;
		f[i]=(!t);
	}
	t=0;ll p=1;
	for(int i=l-1;i>=0;i--){
		t=(p*(s[i]-'0')+t)%b;
		p=(p*10)%b;
		if(!t&&s[i]-'0'!=0)d[i]=1;
	}
	for(int i=0;i<l-1;i++){
		if(f[i]&&d[i+1]){
			puts("YES");
			for(int j=0;j<=i;j++)putchar(s[j]);
			puts("");
			for(int j=i+1;j<l;j++)putchar(s[j]);
			return 0;
		}
	}
	cout<<"NO";
	return 0;
}