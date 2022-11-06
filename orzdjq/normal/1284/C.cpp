#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;
inline int read(){
	int v=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0' && c<='9'){
		v=v*10+c-'0';
		c=getchar();
	}
	return v*f;
}
LL mod;
const int Maxn=250005;
LL fact[Maxn];
int main(){
	int n;
	cin>>n>>mod;
	fact[0]=1;
	for (int i=1;i<Maxn;i++){
		fact[i]=fact[i-1]*i%mod;
	}
	LL ans=0;
	for (int i=1;i<=n;i++){
		LL cc=(n-i+1);
		cc=cc*(n-i+1)%mod*fact[n-i]%mod*fact[i]%mod;
		ans+=cc;ans%=mod; 
	}
	cout<<ans<<endl;
}