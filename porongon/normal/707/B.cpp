#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int n,m,k;
int x[100005],y[100005],d[100005];
int s[100005];

int main(){
	scanf("%d%d%d",&n,&m,&k);
	fore(i,0,m)scanf("%d%d%d",x+i,y+i,d+i),x[i]--,y[i]--;
	fore(i,0,k){
		int w;
		scanf("%d",&w);w--;
		s[w]=1;
	}
	int r=(1<<30);
	fore(i,0,m){
		if(s[x[i]]^s[y[i]])r=min(r,d[i]);
	}
	if(r==(1<<30))puts("-1");
	else printf("%d\n",r);
	return 0;
}