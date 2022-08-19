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
int a[200005],p[200005],cm[200005],b[200005];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint(),p[a[i]]=i;
	for(int i=1;i<=n;i++) b[i]=readint(),cm[b[i]]=i;
	int pl=n,fl=0;
	while(b[pl-1]&&b[pl-1]==b[pl]-1) pl--;
	if(b[pl]==1) fl=1;
	if(!fl){
		int ans=0;
		for(int i=1;i<=n;i++) ans=max(ans,cm[i]+n-i+1);
		cout<<ans<<endl;
	}
	else{
		for(int i=b[n]+1;i<=n;i++) if(cm[i]>i-b[n]-1) fl=0;
		if(!fl){
			int ans=0;
			for(int i=1;i<=n;i++) ans=max(ans,cm[i]+n-i+1);
			cout<<ans<<endl;
		}
		else cout<<n-b[n]<<endl;
	}
	return 0;
}