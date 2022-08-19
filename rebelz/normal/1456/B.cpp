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

int n;
int a[100005],s[100005];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	if(n>60) return printf("1\n"),0;
	for(int i=1;i<=n;i++) s[i]=s[i-1]^a[i];
	int ans=1<<30;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(j<n&&(s[j]^s[i-1])>a[j+1]) chkmin(ans,j-i);
			if(i>1&&(s[j]^s[i-1])<a[i-1]) chkmin(ans,j-i);
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+2;k<=n;k++)
				if((s[j]^s[i-1])>(s[k]^s[j])) chkmin(ans,k-i-1);
	if(ans==(1<<30)) printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}