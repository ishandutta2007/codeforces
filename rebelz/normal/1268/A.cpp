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

int n,k;
int a[200005],cnt[200005],ans[200005];
char s[200005];

int main(){
	n=readint(); k=readint();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) a[i]=s[i]-'0';
	for(int i=1;i<=n;i++) cnt[i]=cnt[i-1]+(a[i]==9);
	int minb=1<<30,mins=1<<30;
	for(int i=1;i<=k;i++){
		for(int j=0;j<=9;j++){
			int ns=mins,nb=minb;
			for(int l=i;l<=n;l+=k){
				if(a[l]>j) chkmin(ns,l);
				if(a[l]<j) chkmin(nb,l);
				if(a[l]!=j) break;
			}
			if(ns>nb){
				ans[i]=j;
				mins=ns,minb=nb;
				break;
			}
			if(ns==(1<<30)){
				ans[i]=j;
				mins=ns,minb=nb;
				break;
			}
			bool fl=0;
			for(int l=1;l<=n;l+=k){
				if(ns>=l+k-1&&cnt[l+k-1]-cnt[l+i-1]!=k-i){
					fl=1;
					break;
				}
			}
			if(fl){
				ans[i]=j;
				mins=ns,minb=nb;
				break;
			}
		}
	}
	printf("%d\n",n);
	for(int i=1;i<=n;i++) printf("%d",ans[(i-1)%k+1]);
	printf("\n");
	return 0;
}