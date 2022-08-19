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
int x[1005],y[1005],a[1005];
vector<int> ans;

int main(){
	n=readint();
	for(int i=1;i<=n;i++) x[i]=readint(),y[i]=readint();
	for(int i=2;;i<<=1){
		cnt=0;
		for(int j=1;j<=n;j++) a[++cnt]=((x[j]+y[j])%i+i)%i;
		sort(a+1,a+cnt+1);
		cnt=unique(a+1,a+cnt+1)-a-1;
		if(cnt>1){
			for(int j=1;j<=n;j++) if(((x[j]+y[j])%i+i)%i==a[1]) ans.push_back(j);
			printf("%d\n",(int)ans.size());
			for(auto x:ans) printf("%d ",x);
			printf("\n");
			return 0;
		}
		cnt=0;
		for(int j=1;j<=n;j++) a[++cnt]=(x[j]%i+i)%i;
		sort(a+1,a+cnt+1);
		cnt=unique(a+1,a+cnt+1)-a-1;
		if(cnt>1){
			for(int j=1;j<=n;j++) if((x[j]%i+i)%i==a[1]) ans.push_back(j);
			printf("%d\n",(int)ans.size());
			for(auto x:ans) printf("%d ",x);
			printf("\n");
			return 0;
		}
	}
	return 0;
}