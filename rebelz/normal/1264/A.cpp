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

int n,cnt;
int a[400005],b[400005];

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		cnt=0;
		for(int i=2;i<=n;i++) if(a[i]!=a[i-1]) b[++cnt]=i;
		int G=-1,S=-1,B=-1;
		G=b[1]-1;
		for(int i=2;i<=cnt;i++){
			if(b[i]-b[1]>G){
				S=b[i]-b[1];
				break;
			}
		}
		for(int i=2;i<=cnt;i++){
			if(b[i]-S-b[1]>G){
				B=b[i]-S-b[1];
				break;
			}
		}
		if(G<0||S<0||B<0) printf("0 0 0\n");
		else if(G+S+B>n/2) printf("0 0 0\n");
		else{
			for(int i=2;i<=cnt;i++) if(b[i]-1<=n/2) chkmax(B,b[i]-S-b[1]);
			printf("%d %d %d\n",G,S,B);
		}
	}
	return 0;
}