#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

bool chkmax(int &x,int y){return x<y?x=y,true:false;}
bool chkmin(int &x,int y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,k;
int a[2][55],b[2][55];
vector<pair<int,pii> > ans;

pii nxt(int x,int y){
	if(x==0){
		if(y>1) return mp(x,y-1);
		else return mp(1,1);
	}
	else{
		if(y<n) return mp(x,y+1);
		else return mp(0,n);
	}
}

int main(){
	n=readint(); k=readint();
	for(int i=1;i<=n;i++) b[0][i]=readint();
	for(int i=1;i<=n;i++) a[0][i]=readint();
	for(int i=1;i<=n;i++) a[1][i]=readint();
	for(int i=1;i<=n;i++) b[1][i]=readint();
	for(int i=0;i<=1;i++) for(int j=1;j<=n;j++) if(a[i][j]==b[i][j]&&a[i][j]>0) ans.push_back(mp(a[i][j],mp(i==0?1:4,j))),a[i][j]=0,k--;
	while(k){
		bool fl=false;
		for(int i=0;i<=1;i++){
			if(i==0){
				for(int j=1;j<=n;j++){
					if(!a[i][j]) continue;
					pii t=nxt(i,j);
					if(!a[t.fi][t.se]){
						ans.push_back(mp(a[i][j],mp(t.fi+2,t.se)));
						fl=true;
						a[t.fi][t.se]=a[i][j],a[i][j]=0;
						if(b[t.fi][t.se]==a[t.fi][t.se]&&a[t.fi][t.se]>0) ans.push_back(mp(a[t.fi][t.se],mp(t.fi==0?1:4,t.se))),a[t.fi][t.se]=0,k--;
					}
				}
			}
			else{
				for(int j=n;j>=1;j--){
					if(!a[i][j]) continue;
					pii t=nxt(i,j);
					if(!a[t.fi][t.se]){
						ans.push_back(mp(a[i][j],mp(t.fi+2,t.se)));
						fl=true;
						a[t.fi][t.se]=a[i][j],a[i][j]=0;
						if(b[t.fi][t.se]==a[t.fi][t.se]&&a[t.fi][t.se]>0) ans.push_back(mp(a[t.fi][t.se],mp(t.fi==0?1:4,t.se))),a[t.fi][t.se]=0,k--;
					}
				}
			}
		}
//		cout<<"k "<<k<<endl;
//		for(int i=0;i<=1;i++){
//			for(int j=1;j<=n;j++) cout<<a[i][j]<<' ';
//			cout<<endl;
//		}
		if(!fl) return printf("-1\n"),0;
	}
	printf("%d\n",ans.size());
	for(auto x:ans) printf("%d %d %d\n",x.fi,x.se.fi,x.se.se);
	return 0;
}