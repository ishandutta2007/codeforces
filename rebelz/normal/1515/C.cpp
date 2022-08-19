#include<bits/stdc++.h>

#define y1 dmytxdy
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,x;
int a[100005];

int main(){
	int T=readint();
	while(T--){
		n=readint(); m=readint(); x=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		priority_queue<pii> q;
		for(int i=1;i<=m;i++) q.push(mp(0,i));
		printf("YES\n");
		for(int i=1;i<=n;i++){
			pii t=q.top(); q.pop();
			q.push(mp(t.fi-a[i],t.se));
			printf("%d ",t.se);
		}
		printf("\n");
	}
	return 0;
}