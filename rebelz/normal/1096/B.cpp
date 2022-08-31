#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll n,l,r;
char s[200005];

int main(){
	n=readint(); scanf("%s",s+1);
	if(s[1]==s[n]){
		for(int i=2;i<=n;i++){
			if(s[i]!=s[i-1]){
				l=i;
				break;
			}
		}
		for(int i=n-1;i>=1;i--){
			if(s[i]!=s[i+1]){
				r=i;
				break;
			}
		}
		cout<<1ll*l*(n-r+1)%998244353<<endl;
	}
	else{
		for(int i=2;i<=n;i++){
			if(s[i]!=s[i-1]){
				l=i;
				break;
			}
		}
		for(int i=n-1;i>=1;i--){
			if(s[i]!=s[i+1]){
				r=i;
				break;
			}
		}
		cout<<(l+(n-r+1)-1)%998244353<<endl;
	}
	return 0;
}