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
int a[2100],p[2100];
vector<int> ans;

void operate(int x){
	ans.pb(x);
	for(int i=1;i<=x/2;i++){
		swap(p[a[i]],p[a[x-i+1]]);
		swap(a[i],a[x-i+1]);
	}
}

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) a[i]=readint(),p[a[i]]=i;
		bool fl=0;
		for(int i=1;i<=n;i++) if((p[i]&1)!=(i&1)) fl=1;
		if(fl){
			printf("-1\n");
			continue;
		}
		ans.clear();
		for(int i=n;i>=3;i-=2){
			operate(p[i]);
			operate(p[i-1]-1);
			operate(p[i-1]+1);
			operate(3);
			operate(i);
		}
		printf("%d\n",ans.size());
		for(auto r:ans) printf("%d ",r);
		printf("\n");
	}
	return 0;
}