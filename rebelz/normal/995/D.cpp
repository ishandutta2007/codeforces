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

int n,r;
ll a[1000005];

int main(){
	n=readint(); r=readint();
	ll sum=0;
	for(int i=0;i<(1<<n);i++) a[i]=readint(),sum+=a[i];
	printf("%.10lf\n",1.0*sum/(1<<n));
	int x,y;
	while(r--){
		x=readint(); y=readint();
		sum+=y-a[x];
		printf("%.10lf\n",1.0*sum/(1<<n));
		a[x]=y;
	}
	return 0;
}