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

int n;
int a[200005];

int main(){
	n=readint();
	if(n%2==0) return printf("NO\n"),0;
	printf("YES\n");
	for(int i=1;i<=n;i++) a[i]=2*i-1+(i&1?0:1),a[i+n]=2*i-1+(i&1?1:0);
	for(int i=1;i<=2*n;i++) printf("%d ",a[i]);
	printf("\n");
	return 0;
}