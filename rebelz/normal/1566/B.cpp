// xtqqwq
#include<bits/stdc++.h>

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
char s[100005];

int main(){
	int T=readint();
	while(T--){
		scanf("%s",s+1);
		n=strlen(s+1);
		int ans=2;
		bool fl=0;
		for(int i=1;i<=n;i++) if(s[i]=='0') fl=1;
		if(!fl){
			printf("0\n");
			continue;
		}
		else{
			int cnt=0,mina=n+1,maxa=0;
			for(int i=1;i<=n;i++) if(s[i]=='0') cnt++,chkmax(maxa,i),chkmin(mina,i);
			if(cnt==maxa-mina+1) printf("1\n");
			else printf("2\n");
		}
	}
	return 0;
}