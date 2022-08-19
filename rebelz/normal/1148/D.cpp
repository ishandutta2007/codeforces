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

struct node{
	int id,x,y;
	node(int ii=0,int xx=0,int yy=0):id(ii),x(xx),y(yy){}
	bool operator<(const node c)const{return x>c.x;}
}k[300005];

int n,cnt1,cnt;
int a[300005],b[300005];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint(),b[i]=readint();
	for(int i=1;i<=n;i++) if(a[i]>b[i]) cnt1++;
	if(cnt1>n-cnt1){
		for(int i=1;i<=n;i++) if(a[i]>b[i]) k[++cnt]=node(i,-b[i],a[i]);
		sort(k+1,k+cnt+1);
		cout<<cnt<<endl;
		for(int i=1;i<=cnt;i++) cout<<k[i].id<<' ';
		cout<<endl;
	}
	else{
		for(int i=1;i<=n;i++) if(a[i]<b[i]) k[++cnt]=node(i,b[i],a[i]);
		sort(k+1,k+cnt+1);
		cout<<cnt<<endl;
		for(int i=1;i<=cnt;i++) cout<<k[i].id<<' ';
		cout<<endl;
	}
	return 0;
}