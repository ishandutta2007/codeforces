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
int a[1005],hv[1005];
bool vis[1005];
pii p[1005];
vector<int> ans;

int getmex(){
	for(int i=1;i<=n;i++) vis[a[i]]=1;
	int ret=0;
	for(int i=0;i<=n;i++){
		if(!vis[i]){
			ret=i;
			break;
		}
	}
	for(int i=0;i<=n;i++) vis[i]=0;
	return ret;
}

void oper(int x){
	if(x>n) return;
	ans.pb(x);
	for(int i=1;i<=n;i++) vis[a[i]]=1;
	for(int i=0;i<=n;i++){
		if(!vis[i]){
			a[x]=i;
			break;
		}
	}
	for(int i=0;i<=n;i++) vis[i]=0;
}

void print(){
	cout<<"Test ";
	for(int i=1;i<=n;i++) cout<<a[i]<<' ';
	cout<<endl;
}

void getans(int now){
	bool fl=1;
	for(int i=1;i<n;i++) if(a[i]>a[i+1]) fl=0;
	if(fl) return;
	int tmp=a[now];
	oper(now);
	if(!hv[tmp+1]) getans(tmp+1);
}

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		for(int i=1;i<=n;i++) hv[i]=0;
		hv[0]=2;
		ans.clear();
		int cnt=0;
		while(1){
			int mex=getmex();
			if(hv[mex]<2) oper(mex),hv[mex]++,cnt++;
			else oper(mex+1),hv[mex+1]=2,cnt++;
			if(cnt==n*2) break;
		}
		printf("%d\n",ans.size());
		for(auto x:ans) printf("%d ",x);
		printf("\n");
	}
	return 0;
}