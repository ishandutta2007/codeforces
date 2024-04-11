#include<bits/stdc++.h>

#define y1 dmytxdy
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

bool chkmin(int &x,int y){return x>y?x=y,1:0;}
bool chkmax(int &x,int y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
char s[1000005];

int main(){
	n=readint(); scanf("%s",s+1);
	if(n&1) return printf("No\n"),0;
	int cnt=0;
	for(int i=1;i<=n;i++) cnt+=s[i]=='(';
	if(cnt!=n/2) return printf("No\n"),0;
	int now=0,ans=0;
	for(int i=1;i<=n;i++){
		now+=s[i]=='('?1:-1;
		ans=min(ans,now);
	}
	if(ans>=-1) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}