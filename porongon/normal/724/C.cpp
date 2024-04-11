#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int d(int x0, int y0, int x1, int y1){
	int dx=abs(x0-x1);
	int dy=abs(y0-y1);
	assert(dx==dy);
	return dx;
}

int n,m,k;
map<int,vector<int> > s[2];  // 0 resta, 1 suma
int xs[100005];
int ys[100005];
ll r[100005];

int main(){
	scanf("%d%d%d",&n,&m,&k);
	fore(i,0,k){
		r[i]=(1LL<<62);
		scanf("%d%d",xs+i,ys+i);
		s[0][xs[i]-ys[i]].pb(i);
		s[1][xs[i]+ys[i]].pb(i);
	}
	int x0=1,y0=1,x=0,y=0;
	ll t=0;
	while(1){
		assert(x>=0&&x<=n&&y>=0&&y<=m);
		//printf("%d %d %d %d\n",x,y,x0,y0);
		if(x0==y0){
			if(s[0].count(x-y)){
				vector<int> &v=s[0][x-y];
				fore(i,0,v.size()){
					int j=v[i];
					r[j]=min(r[j],t+d(x,y,xs[j],ys[j]));
				}
			}
		}
		else {
			if(s[1].count(x+y)){
				vector<int> &v=s[1][x+y];
				fore(i,0,v.size()){
					int j=v[i];
					r[j]=min(r[j],t+d(x,y,xs[j],ys[j]));
				}
			}
		}
		if(x0==1&&y0==1){
			if(n-x==m-y)break;
			if(n-x<m-y)x0=-1;
			else y0=-1;
			int i=min(n-x,m-y);
			t+=i;
			x+=i;
			y+=i;
		}
		else if(x0==1&&y0==-1){
			if(n-x==y)break;
			if(n-x<y)x0=-1;
			else y0=1;
			int i=min(n-x,y);
			t+=i;
			x+=i;
			y-=i;

		}
		else if(x0==-1&&y0==1){
			if(x==m-y)break;
			if(x<m-y)x0=1;
			else y0=-1;
			int i=min(x,m-y);
			t+=i;
			x-=i;
			y+=i;

		}
		else if(x0==-1&&y0==-1){
			if(x==y)break;
			if(x<y)x0=1;
			else y0=1;
			int i=min(x,y);
			t+=i;
			x-=i;
			y-=i;
		}
	}
	fore(i,0,k){
		if(r[i]==(1LL<<62))puts("-1");
		else printf("%I64d\n",r[i]);
	}
	return 0;
}