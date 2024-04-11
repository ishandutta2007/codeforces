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

int a,b,c,d;

int main(){
	a=readint(); b=readint(); c=readint(); d=readint();
	if(a==b+1&&c==0&&d==0){
		printf("YES\n");
		printf("0 ");
		for(int i=1;i<=b;i++) printf("1 0 ");
		printf("\n");
		return 0;
	}
	if(d==c+1&&a==0&&b==0){
		printf("YES\n");
		printf("3 ");
		for(int i=1;i<=c;i++) printf("2 3 ");
		printf("\n");
		return 0;
	}
	if(a>b||d>c) return printf("NO\n"),0;
	int a1=a,a2=b-a,b1=d,b2=c-d;
	if(abs(a2-b2)>1) return printf("NO\n"),0;
	if(a2>b2){
		printf("YES\n");
		for(int i=1;i<=b1;i++) printf("3 2 ");
		printf("1 "); a2--;
		for(int i=1;i<=a1;i++) printf("0 1 ");
		for(int i=1;i<=a2;i++) printf("2 1 ");
		printf("\n");
	}
	else if(a2<b2){
		printf("YES\n");
		for(int i=1;i<=a1;i++) printf("0 1 ");
		printf("2 "); b2--;
		for(int i=1;i<=b1;i++) printf("3 2 ");
		for(int i=1;i<=a2;i++) printf("1 2 ");
		printf("\n");
	}
	else{
		if(a2==0){
			printf("YES\n");
			for(int i=1;i<=a1;i++) printf("0 1 ");
			for(int i=1;i<=b1;i++) printf("2 3 ");
			printf("\n");
			return 0;
		}
		printf("YES\n");
		printf("1 "); a2--;
		for(int i=1;i<=a1;i++) printf("0 1 ");
		printf("2 "); b2--;
		for(int i=1;i<=b1;i++) printf("3 2 ");
		for(int i=1;i<=a2;i++) printf("1 2 ");
		printf("\n");
	}
	return 0;
}