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

int n,m;
int a[255][255],d1[255],d2[255],ans[255][255];
pii pl[700000];
vector<pii> vec;

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]=readint();
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) chkmax(d1[i],a[i][j]),chkmax(d2[j],a[i][j]);
	for(int i=1;i<=n;i++) vec.pb(mp(d1[i],0));
	for(int i=1;i<=m;i++) vec.pb(mp(d2[i],1));
	sort(vec.begin(),vec.end());
	int x=0,y=0;
	for(int i=vec.size()-1;i>=0;i--){
		if(i&&vec[i].fi==vec[i-1].fi) x++,y++,i--;
		else if(vec[i].se==0) x++;
		else y++;
		ans[x][y]=vec[i].fi,pl[vec[i].fi]=mp(x,y);
	}
	int now=1;
	while(pl[now].fi) now++;
	for(int i=0;i<vec.size();i++){
		if(vec[i].se==0){
			for(int j=1;j<pl[vec[i].fi].se;j++){
				ans[pl[vec[i].fi].fi][j]=now;
				now++;
				while(pl[now].fi) now++;
			}
		}
		else{
			for(int j=1;j<pl[vec[i].fi].fi;j++){
				ans[j][pl[vec[i].fi].se]=now;
				now++;
				while(pl[now].fi) now++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) printf("%lld ",ans[i][j]);
		printf("\n");
	}
	return 0;
}