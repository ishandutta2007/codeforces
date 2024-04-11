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
char s[300005];
bool can[300005];

int main(){
	int T=readint();
	while(T--){
		n=readint();
		scanf("%s",s+1);
		bool fl1=1,fl2=1;
		for(int i=0;i<=n;i++) can[i]=0;
		for(int i=1;i<=n;i++) if(s[i]!='>'&&s[i]!='-') fl1=0;
		for(int i=1;i<=n;i++) if(s[i]!='<'&&s[i]!='-') fl2=0;
		if(fl1||fl2){
			printf("%d\n",n);
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++) if(s[i]=='-') can[i%n]=can[i-1]=1;
		for(int i=0;i<n;i++) if(can[i]) ans++;
		printf("%d\n",ans);
	}
	return 0;
}