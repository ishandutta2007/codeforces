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
char s[200005];
int now[200005];
pii p[200005];

int main(){
	int T=readint();
	while(T--){
		n=readint();
		scanf("%s",s+1);
		for(int i=1;i<=n;i++) p[i]=mp(s[i]-'0',i),now[i]=2;
		sort(p+1,p+n+1);
		int pl=n;
		for(int i=2;i<=n;i++){
			if(p[i].se<p[i-1].se){
				pl=i-1;
				break;
			}
		}
		if(pl==n){
			for(int i=1;i<=n;i++) printf("1");
			printf("\n");
			continue;
		}
		int num=p[pl+1].fi,fl=0;
		for(int i=1;i<=pl;i++) now[p[i].se]=1;
		for(int i=p[pl].se+1;i<=n;i++) if(s[i]-'0'==num) now[i]=1;
		for(int i=1;i<=n;i++){
			if(now[i]==2){
				if(s[i]-'0'<num) fl=1;
				chkmax(num,(int)s[i]-'0');
			}
		}
		if(fl) printf("-\n");
		else{
			for(int i=1;i<=n;i++) printf("%d",now[i]);
			printf("\n");
		}
	}
	return 0;
}