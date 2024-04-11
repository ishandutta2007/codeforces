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
char s[3][200005];

int main(){
	int T=readint();
	while(T--){
		n=readint();
		scanf("%s%s%s",s[0]+1,s[1]+1,s[2]+1);
		int now[3]={1,1,1};
		while(now[0]<=n+n&&now[1]<=n+n&&now[2]<=n+n){
			int cnt[2]={0,0},cho=-1;
			for(int i=0;i<3;i++) cnt[s[i][now[i]]-'0']++;
			if(cnt[0]>cnt[1]) cho=0;
			else cho=1;
			putchar(cho+'0');
			for(int i=0;i<3;i++) if(s[i][now[i]]-'0'==cho) now[i]++;
		}
		int pl=-1;
		if(now[0]>n+n){
			if(now[1]>now[2]) pl=1;
			else pl=2;
		}
		else if(now[1]>n+n){
			if(now[0]>now[2]) pl=0;
			else pl=2;
		}
		else if(now[2]>n+n){
			if(now[0]>now[1]) pl=0;
			else pl=1;
		}
		for(int i=now[pl];i<=n+n;i++) putchar(s[pl][i]);
		puts("");
	}
	return 0;
}