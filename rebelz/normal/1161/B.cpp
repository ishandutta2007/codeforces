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

struct hsh{
	size_t operator()(const pii c)const{
		return (c.fi*19260817+c.se)&INT_MAX;
	}
};

int n,m;
int a[200005];
pii k[200005];
unordered_map<pii,int,hsh> b;

bool solve(int g){
	for(int j=1;j<=m;j++){
		int x=k[j].fi-g,y=k[j].se-g;
		if(x<=0) x+=n;
		if(y<=0) y+=n;
		if(x>y) swap(x,y);
		if(!b[mp(x,y)]) return false;
	}
	return true;
}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=m;i++){
		k[i].fi=readint(); k[i].se=readint();
		if(k[i].fi>k[i].se) swap(k[i].fi,k[i].se);
		b[k[i]]=1;
	}
	for(int i=2;i<=sqrt(n);i++){
		if(n%i!=0) continue;
		if(solve(i)||solve(n/i)) return printf("Yes\n"),0;
	}
	if(solve(1)) printf("Yes\n");
	else printf("No\n");
	return 0;
}