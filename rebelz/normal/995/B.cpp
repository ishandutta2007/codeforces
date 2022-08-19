#include<bits/stdc++.h>

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

int n;
int a[100005];
vector<int> v[100005];

int main(){
	n=readint();
	for(int i=1;i<=2*n;i++) a[i]=readint();
	int ans=0,fd;
	for(int i=1;i<=2*n;i+=2){
		if(a[i]==a[i+1]) continue;
		for(int j=i+1;j<=2*n;j++) if(a[j]==a[i]) fd=j;
		ans+=fd-i-1;
		for(int j=fd;j>=i+2;j--) a[j]=a[j-1];
	}
	cout<<ans<<endl;
	return 0;
}