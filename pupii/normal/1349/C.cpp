#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
std::mt19937 rnd(time(NULL));
#define rand rnd
#define pr std::pair<int,int>
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
template<class T>void cxk(T&a,T b){a=a>b?a:b;}
template<class T>void cnk(T&a,T b){a=a<b?a:b;}
#ifdef mod
int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
template<class Ta,class Tb>void inc(Ta&a,Tb b){a=a+b>=mod?a+b-mod:a+b;}
template<class Ta,class Tb>void dec(Ta&a,Tb b){a=a>=b?a-b:a+mod-b;}
#endif
std::queue<pr>que;
int tim[1010][1010];
char map[1010][1010];
int main(){
#ifdef LOCAL
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi(),t=gi();
	for(int i=1;i<=n;++i)scanf("%s",map[i]+1);
	memset(tim,-1,sizeof tim);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
			if(map[i][j]==map[i][j+1])tim[i][j]=tim[i][j+1]=0,que.push({i,j}),que.push({i,j+1});
			if(map[i][j]==map[i+1][j])tim[i][j]=tim[i+1][j]=0,que.push({i,j}),que.push({i+1,j});
		}
	static int mx[]={1,0,-1,0},my[]={0,1,0,-1};
	for(int t=1;t<=2000;++t){
		int sz=que.size();
		while(sz--){
			int x=que.front().fi,y=que.front().se;que.pop();
			for(int i=0,nx,ny;i<4;++i){
				nx=x+mx[i],ny=y+my[i];
				if(!map[nx][ny])continue;
				if(tim[nx][ny]==-1)tim[nx][ny]=t,que.push({nx,ny});
			}
		}
	}
	while(t--){
		int x=gi(),y=gi();ll p=gi();
		if(tim[x][y]==-1||p<=tim[x][y])printf("%c\n",map[x][y]);
		else printf("%d\n",(map[x][y]-'0')^(p-tim[x][y]&1));
	}
	return 0;
}