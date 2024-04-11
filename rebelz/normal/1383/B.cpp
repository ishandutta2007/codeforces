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
int a[100005],cnt[35];

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		for(int i=0;i<=30;i++) cnt[i]=0;
		for(int i=1;i<=n;i++) for(int j=0;j<=30;j++) if((a[i]>>j)&1) cnt[j]++;
		int now=-1,num=0;
		for(int i=30;i>=0;i--){
			if(cnt[i]&1){
				now=i,num=cnt[i];
				break;
			}
		}
		if(now<0){
			printf("DRAW\n");
			continue;
		}
		if(num%4==1) printf("WIN\n");
		else if(n&1) printf("LOSE\n");
		else printf("WIN\n");
	}
	return 0;
}