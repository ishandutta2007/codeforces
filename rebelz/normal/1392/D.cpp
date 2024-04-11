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
char s[400005];

int main(){
	int T=readint();
	while(T--){
		n=readint();
		scanf("%s",s+1);
		bool fl=0;
		for(int i=1;i<n;i++) if(s[i]!=s[i+1]) fl=1;
		if(!fl){
			printf("%d\n",1+(n-1)/3);
			continue;
		}
		for(int i=n+1;i<=n+n;i++) s[i]=s[i-n];
		int st=0;
		for(int i=1;i<=n;i++){
			if(s[i]!=s[1]){
				st=i;
				break;
			}
		}
		int now=1,ans=0;
		for(int i=st+1;i<=st+n-1;i++){
			if(s[i]==s[i-1]) now++;
			else ans+=now/3,now=1;
		}
		ans+=now/3;
		printf("%d\n",ans);
	}
	return 0;
}