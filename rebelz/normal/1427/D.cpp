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
int pos[55],a[55],tmp[55];
vector<vector<int> > ans;

void work(){
	for(int i=1;i<=n;i++) pos[a[i]]=i;
	int lst=pos[1],opt=0;
	for(int i=2;i<=n;i++){
		if(pos[i]<pos[i-1]){
			opt=i;
			break;
		}
	}
	if(!opt){
		printf("%d\n",ans.size());
		for(auto r:ans){
			printf("%d ",r.size());
			for(auto g:r) printf("%d ",g);
			printf("\n");
		}
		exit(0);
	}
	int pl=pos[opt];
	while(pl<n&&a[pl+1]==a[pl]+1) pl++;
	vector<int> now(0);
	if(pos[opt]>1) now.pb(pos[opt]-1);
	now.pb(pl-pos[opt]+1);
	now.pb(pos[opt-1]-pl);
	if(pos[opt-1]<n) now.pb(n-pos[opt-1]);
	ans.pb(now);
	int m=0;
	for(int i=pos[opt-1]+1;i<=n;i++) tmp[++m]=a[i];
	for(int i=pl+1;i<=pos[opt-1];i++) tmp[++m]=a[i];
	for(int i=pos[opt];i<=pl;i++) tmp[++m]=a[i];
	for(int i=1;i<pos[opt];i++) tmp[++m]=a[i];
	swap(a,tmp);
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	while(1) work();
	return 0;
}