#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct point{
	ll x,y;
	point(ll x=0,ll y=0):x(x),y(y){}
	bool operator<(const point c)const{return x==c.x?y<c.y:x<c.x;}
	point operator-(const point c)const{return point(x-c.x,y-c.y);}
	ll operator*(const point c)const{return x*c.y-y*c.x;}
}k[100005];

int n,m;
int q[100005];

bool comp(int x,int y,int t){return (k[x]-k[y])*(k[t]-k[x])>=0;}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) k[i].x=readint(),k[i].y=readint();
	for(int i=1;i<=n;i++) k[i].y-=k[i].x*k[i].x;
	sort(k+1,k+n+1);
	int front=0,rear=0;
	for(int i=1;i<=n;i++){
		while(rear>1&&comp(q[rear-1],q[rear-2],i)) rear--;
		q[rear++]=i;
	}
	int ans=0;
	for(int i=0;i<rear-1;i++) if(k[q[i]].x<k[q[i+1]].x) ans++;
	cout<<ans<<endl;
	return 0;
}