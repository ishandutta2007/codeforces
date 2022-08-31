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

int n,k,cnt1,cnt2,pl,fir,sec;

int main(){
	n=readint(); k=readint();
	printf("? ");
	for(int i=1;i<=k;i++) printf("%d ",i);
	printf("\n");
	fflush(stdout);
	pl=readint(); fir=readint();
	cnt1=1;
	printf("? ");
	for(int i=1;i<=k+1;i++) if(i!=pl) printf("%d ",i);
	printf("\n");
	fflush(stdout);
	int tmp=readint(); sec=readint();
	cnt2=1;
	for(int i=1;i<=k;i++){
		if(i==pl) continue;
		printf("? ");
		for(int j=1;j<=k+1;j++) if(j!=i) printf("%d ",j);
		printf("\n");
		fflush(stdout);
		tmp=readint(); tmp=readint();
		if(tmp==fir) cnt1++;
		else if(tmp==sec) cnt2++;
		else assert(0);
	}
	if(fir>sec) printf("! %d\n",cnt1);
	else printf("! %d\n",cnt2);
	return 0;
}