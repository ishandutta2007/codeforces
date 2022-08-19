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
int a[200005],b[200005],s[200005];

int main(){
	int T=readint();
	while(T--){
		n=readint(); k=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		for(int i=1;i<=n;i++) s[i]=0;
		for(int i=1;i<=n;i++) s[a[i]]++;
		int t=0;
		for(int i=1;i<=n;i++){
			if(i-(n-i)>=k){
				t=i;
				break;
			}
		}
		int pl=0;
		for(int i=1;i<=n;i++) s[i]+=s[i-1];
		int mina=n+1,lf=0;
		for(int i=1;i<=n;i++){
			while(s[i]-s[pl+1]>=t) pl++;
			if(s[i]-s[pl]>=t){
				if(chkmin(mina,i-pl)) lf=pl+1;
			}
		}
		printf("%d %d\n",lf,lf+mina-1);
		for(int i=1;i<=n;i++) b[i]=a[i]>=lf&&a[i]<=lf+mina-1?1:-1;
		for(int i=1;i<=n;i++) b[i]+=b[i-1];
		int now=0,lst=0;
		for(int i=1;i<=n;i++){
			if(b[i]==now+1&&now+1!=k){
				printf("%d %d\n",lst+1,i);
				lst=i;
				now++;
			}
		}
		printf("%d %d\n",lst+1,n);
	}
	return 0;
}