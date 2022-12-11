#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

vector<int> g[300005];
int n;
int a[300005];
multiset<int> w;

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",a+i),w.insert(-a[i]);
	fore(i,1,n){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	int r=1<<30;
	fore(i,0,n){
		int rr=-(1<<30);
		rr=max(rr,a[i]);
		w.erase(w.find(-a[i]));
		for(int j:g[i]){
			rr=max(rr,a[j]+1);
			w.erase(w.find(-a[j]));
		}
		if(!w.empty())rr=max(rr,-*w.begin()+2);
		w.insert(-a[i]);
		for(int j:g[i]){
			w.insert(-a[j]);
		}
		r=min(r,rr);
	}
	printf("%d\n",r);
	return 0;
}