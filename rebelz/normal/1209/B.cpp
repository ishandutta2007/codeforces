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

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
char s[105];
int a[105],b[105];

int main(){
	n=readint();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) a[i]=readint(),b[i]=readint();
	int ans=0;
	for(int j=1;j<=n;j++) ans+=s[j]-'0';
	for(int i=1;i<=100000;i++){
		for(int j=1;j<=n;j++)
			if(i%a[j]==b[j]%a[j]&&i>=b[j]) s[j]='0'+((s[j]-'0')^1);
		int cnt=0;
		for(int j=1;j<=n;j++) cnt+=s[j]-'0';
		chkmax(ans,cnt);
	}
	printf("%d\n",ans);
	return 0;
}