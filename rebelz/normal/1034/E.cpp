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

int n; ll all;
int cnt[2100000];
char s[2100000];
ll a[2100000],b[2100000];

void fmt(ll *A){
	for(int i=1;i<(1<<n);i<<=1)
		for(int j=0;j<(1<<n);j+=(i<<1))
			for(int k=j;k<j+i;k++)
				A[k+i]=(A[k+i]+A[k])&all;
}

void ifmt(ll *A){
	for(int i=1;i<(1<<n);i<<=1)
		for(int j=0;j<(1<<n);j+=(i<<1))
			for(int k=j;k<j+i;k++)
				A[k+i]-=A[k],A[k+i]=A[k+i]<0?A[k+i]+all+1:A[k+i];
}

int main(){
	n=readint();
	for(int i=1;i<(1<<n);i++) cnt[i]=cnt[i>>1]+(i&1);
	scanf("%s",s);
	for(int i=0;i<(1<<n);i++) a[i]=(ll)(s[i]-'0')<<(cnt[i]<<1);
	scanf("%s",s);
	for(int i=0;i<(1<<n);i++) b[i]=(ll)(s[i]-'0')<<(cnt[i]<<1);
	all=(1ll<<(2*n+2))-1;
	fmt(a); fmt(b);
	for(int i=0;i<(1<<n);i++) a[i]=(a[i]&((1<<(n+1))-1))*b[i]+((((a[i]>>(n+1))*b[i])&((1<<(n+1))-1))<<(n+1));
	ifmt(a);
	for(int i=0;i<(1<<n);i++) printf("%d",(a[i]/(1ll<<(cnt[i]<<1)))&3);
	printf("\n");
	return 0;
}