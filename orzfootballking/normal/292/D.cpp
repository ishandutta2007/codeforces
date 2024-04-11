#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
P<int,int> p[10005];
V<P<int,int> > po;
int n,m,lp[10005],rp[10005],ans[505][505],lpo[505],rpo[505]; 
class dsu{
	public:
    int fa[505],si[505],len;
    void init(){
        FOR(i,1,n){
            fa[i]=i;
            si[i]=1;
        }
        len=n;
    }
    int get(int x){
        while(x!=fa[x])x=fa[x];
        RE x;
    }
    bool up(int a,int b){
        a=get(a);
        b=get(b);
        if(a==b)RE 0;
        if(si[a]<si[b]){
            fa[a]=b;
            si[b]+=si[a];
        }else{
            fa[b]=a;
            si[a]+=si[b];
        }
        len--;
        RE 1;
    }
};
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	cin>>n>>m;
	FOR(i,1,m)cin>>p[i].F>>p[i].S;
	dsu d;
	d.init();
	FOR(i,1,m){
		if(d.up(p[i].F,p[i].S)){
			lp[i]=1;
		}
//		cout<<lp[i]<<' ';
		if(lp[i])lpo[lp[i-1]+1]=i;
		lp[i]+=lp[i-1];
	}
//	cout<<'\n';
	d.init();
	for(int i=m;i>=1;i--){
		if(d.up(p[i].F,p[i].S)){
			rp[i]=1;
		}
//		cout<<rp[i]<<' ';
		if(rp[i])rpo[rp[i+1]+1]=i;
		rp[i]+=rp[i+1];
	}
//	cout<<'\n';
	d.init();
	dsu td;
	FOR(i,0,n-1){
		if(i)d.up(p[lpo[i]].F,p[lpo[i]].S);
		td=d;
		FOR(j,0,n-1){
			if(j)td.up(p[rpo[j]].F,p[rpo[j]].S);
			ans[i][j]=td.len;
//			cout<<ans[i][j]<<' ';
		}
//		cout<<'\n';
	}
	int k,x,y;
	cin>>k;
	FOR(i,1,k){
		cin>>x>>y;
		cout<<ans[lp[x-1]][rp[y+1]]<<'\n';
	}
	RE 0;
}