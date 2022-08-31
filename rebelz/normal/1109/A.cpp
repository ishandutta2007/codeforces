#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
ll ans=0;
ll a[300005],k1[1100000],k2[1100000],s[300005];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	k2[0]++;
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]^a[i];
		if(i&1) ans+=k1[s[i]],k1[s[i]]++;
		else ans+=k2[s[i]],k2[s[i]]++;
	}
	cout<<ans<<endl;
	return 0;
}