#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

char s[300005];
ll n,ans;

int main(){
	scanf("%s",s+1); n=strlen(s+1);
	for(int i=1;i<=n;i++){
		ll mina=1ll<<60;
		for(int j=i;j<=i+20;j++)
			for(int k=j+1;2*k-j<=i+20;k++)
				if(s[j]==s[k]&&s[j]==s[2*k-j]&&2*k-j<=n) mina=min(mina,2ll*k-j);
		if(mina!=1ll<<60) ans+=n-mina+1;
	}
	cout<<ans<<endl;
	return 0;
}