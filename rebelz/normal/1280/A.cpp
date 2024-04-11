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

const int cys=1000000007;
int n,x;
char s[3000005];

int main(){
	int T=readint();
	while(T--){
		x=readint();
		scanf("%s",s+1); n=strlen(s+1);
		ll now=n,pl=0,ttmp=0;
		bool fl=0;
		for(int i=1;i<=x;i++){
			pl++;
			if(!fl){
				ll tmp=now;
				for(int j=1;j<=s[pl]-'1';j++){
					for(int k=pl+1;k<=now;k++) s[tmp+k-pl]=s[k];
					tmp+=now-pl;
				}
			}
			ttmp+=(now-pl)*(s[pl]-'1');
			now=(now+(cys+now-pl)*(s[pl]-'1'))%cys;
			if(ttmp>x) fl=1;
		}
		printf("%lld\n",now);
	}
	return 0;
}