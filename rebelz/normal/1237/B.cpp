#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

bool chkmax(int &x,int y){return x<y?x=y,true:false;}
bool chkmin(int &x,int y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,ans;
int a[100005],b[100005];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[readint()]=n-i+1;
	for(int i=1;i<=n;i++) b[n-i+1]=a[readint()];
	int mx=0;
	for(int i=1;i<=n;i++){
		if(b[i]<mx) ans++;
		chkmax(mx,b[i]);
	}
	cout<<ans<<endl;
	return 0;
}