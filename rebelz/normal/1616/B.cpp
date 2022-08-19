// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

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
		n=readint();
		scanf("%s",s+1);
		if(s[1]==s[2]){
			printf("%c%c",s[1],s[1]);
			putchar('\n');
			continue;
		}
		int pl=n;
		for(int i=1;i<n;i++){
			if(s[i]<s[i+1]){
				pl=i;
				break;
			}
		}
		for(int i=1;i<=pl;i++) putchar(s[i]);
		for(int i=pl;i>=1;i--) putchar(s[i]);
		putchar('\n');
	}
	return 0;
}