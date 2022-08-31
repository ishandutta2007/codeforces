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

int n,m,q;
int a[1000005];
char s[1000005],str[1000005];

int id(int x,int y){return (x-1)*m+y;}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=n;i++){
		scanf("%s",str+1);
		for(int j=1;j<=m;j++) s[id(i,j)]=str[j];
	}
	for(int i=1;i<n;i++)
		for(int j=1;j<m;j++)
			if(s[id(i+1,j)]=='X'&&s[id(i,j+1)]=='X')
				a[j]=1;
	for(int i=1;i<=m;i++) a[i]+=a[i-1];
	q=readint();
	int x,y;
	while(q--){
		x=readint(); y=readint();
		if(a[y-1]-a[x-1]) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}