#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

vector<int> g[300005];
bool p[300005],v[300005];
int ex[300005],ey[300005],f[300005];
set<int> r;
queue<int> q;
int n,k,_d;

int main(){
	scanf("%d%d%d",&n,&k,&_d);
	fore(i,0,k){
		int x;
		scanf("%d",&x);x--;
		p[x]=true;
	}
	fore(i,0,n-1){
		scanf("%d%d",ex+i,ey+i);ex[i]--;ey[i]--;
		g[ex[i]].pb(i);
		g[ey[i]].pb(i);
	}
	k=0;
	fore(i,0,n)if(p[i]){
		k++;
		v[i]=true;f[i]=-1;
		q.push(i);
	}
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i:g[x]){
			int y=ex[i]^ey[i]^x;
			if(!v[y]){
				v[y]=true;
				f[y]=x;
				q.push(y);
			}
			else if(f[x]!=y)r.insert(i);
		}
	}
	assert(r.size()==k-1);
	printf("%d\n",(int)r.size());
	bool p=false;
	for(int i:r){
		if(p)putchar(' ');
		p=true;
		printf("%d",i+1);
	}
	puts("");
	return 0;
}