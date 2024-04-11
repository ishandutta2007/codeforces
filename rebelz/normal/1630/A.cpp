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

int n,k;

int main(){
	int T=readint();
	while(T--){
		n=readint(); k=readint();
		if(n-1==k){
			if(n==4) printf("-1\n");
			else{
				printf("%d %d\n",n-1,n-2);
				printf("%d %d\n",1,3);
				printf("%d %d\n",0,n-4);
				for(int i=1;i<n/2;i++) if(i!=1&&i!=3&&i!=n-2&&i!=n-3) printf("%d %d\n",i,n-1-i);
			}
		}
		else if(k==0){
			for(int i=0;i<n/2;i++) printf("%d %d\n",i,n-1-i);
		}
		else{
			printf("0 %d\n",n-1-k);
			printf("%d %d\n",k,n-1);
			for(int i=1;i<n/2;i++) if(i!=k&&i!=n-1-k) printf("%d %d\n",i,n-1-i);
		}
	}
	return 0;
}