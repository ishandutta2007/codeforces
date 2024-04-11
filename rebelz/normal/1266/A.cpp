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
		scanf("%s",s+1); n=strlen(s+1);
		int t1=0;
		for(int i=1;i<=n;i++) t1+=s[i]-'0';
		if(t1%3!=0){
			printf("cyan\n");
			continue;
		}
		bool f1=false;
		for(int i=1;i<=n;i++) f1|=s[i]=='0';
		if(!f1){
			printf("cyan\n");
			continue;
		}
		int t2=0;
		for(int i=1;i<=n;i++) t2+=(s[i]-'0')%2==0;
		if(t2<=1){
			printf("cyan\n");
			continue;
		}
		else printf("red\n");
	}
	return 0;
}