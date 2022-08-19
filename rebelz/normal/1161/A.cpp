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

int n,k,ans;
int a[100005],cnt[100005],mina[100005],maxa[100005];

int main(){
	memset(mina,0x3f,sizeof(mina));
	n=readint(); k=readint();
	for(int i=1;i<=k;i++) a[i]=readint(),cnt[a[i]]++,mina[a[i]]=min(mina[a[i]],i),maxa[a[i]]=max(maxa[a[i]],i);
	for(int i=1;i<=n;i++) if(!cnt[i]) ans++;
	for(int i=1;i<=n-1;i++){
		if(cnt[i]==0||cnt[i+1]==0) ans++;
		else if(mina[i]>maxa[i+1]) ans++;
	}
	for(int i=2;i<=n;i++){
		if(cnt[i]==0||cnt[i-1]==0) ans++;
		else if(mina[i]>maxa[i-1]) ans++;
	}
	cout<<ans<<endl;
	return 0;
}