#include<bits/stdc++.h>
#define il inline
#define vd void
#define int long long
typedef long long ll;
#define mp std::make_pair
il int gi(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int n,m,r,c,x,y;
char s[2010][2010];
bool vis[2010][2010];
int L[2010][2010];
std::priority_queue<std::pair<int,std::pair<int,int> > >que;
il int dist(int x,int y,int d){
	if(y>c)return y-c+d;
	else return d-(c-y);
}
main(){
#ifndef ONLINE_JUDGE
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
#endif
	n=gi(),m=gi();
	r=gi(),c=gi();
	x=gi(),y=gi();
	for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
	int X,Y;
	memset(L,63,sizeof L);
	vis[r][c]=1;
	L[r][c]=0;
	que.push(mp(0,mp(r,c)));
	int ans=0;
	while(!que.empty()){
		X=que.top().second.first,Y=que.top().second.second;
		++ans;
		vis[X][Y]=1;
		if(s[X-1][Y]=='.'&&L[X-1][Y]>L[X][Y]){
			L[X-1][Y]=L[X][Y];
			que.push(mp(-L[X-1][Y],mp(X-1,Y)));
		}
		if(s[X+1][Y]=='.'&&L[X+1][Y]>L[X][Y]){
			L[X+1][Y]=L[X][Y];
			que.push(mp(-L[X+1][Y],mp(X+1,Y)));
		}
		if(s[X][Y-1]=='.'&&L[X][Y-1]>L[X][Y]+1&&L[X][Y]+1<=x&&dist(X,Y-1,L[X][Y]+1)<=y){
			L[X][Y-1]=L[X][Y]+1;
			que.push(mp(-L[X][Y-1],mp(X,Y-1)));
		}
		if(s[X][Y+1]=='.'&&L[X][Y+1]>L[X][Y]&&dist(X,Y+1,L[X][Y])<=y){
			L[X][Y+1]=L[X][Y];
			que.push(mp(-L[X][Y+1],mp(X,Y+1)));
		}
		while(!que.empty()&&vis[que.top().second.first][que.top().second.second])que.pop();
	}
	printf("%lld\n",ans);
	return 0;
}