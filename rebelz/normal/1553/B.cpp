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

int n,m;
char s[505],t[1005];

int main(){
	int T=readint();
	while(T--){
		scanf("%s%s",s+1,t+1);
		n=strlen(s+1);
		m=strlen(t+1);
		bool fl=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				bool fl1=1,fl2=1;
				for(int k=j;k>=1;k--) if(i+k-j<1||s[i+k-j]!=t[k]) fl1=0;
				if(!fl1) continue;
				for(int k=j+1;k<=m;k++) if(i-k+j<1||s[i-k+j]!=t[k]) fl2=0;
				if(!fl2) continue;
				fl=1;
				printf("YES\n");
				break;
			}
			if(fl) break;
		}
		if(!fl) printf("NO\n");
	}
	return 0;
}