#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&(-x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
#define ls(x) x<<1
#define rs(x) x<<1|1
using namespace std;
const int N=3e5+9;
const ll mod=998244353;
int sg[6][6][6][200][3],vis[5];
char s[6][6][6][210];
int m[6][6][6],nex[210];
ll a[N];
int solve(char *p){
	int plen=strlen(p);
	nex[0]=-1;
	int i=0,j=-1;
	while(i<plen-1){
		if(j==-1||p[i]==p[j]){
			++i,++j;
			if(p[i]!=p[j])nex[i]=j;
			else nex[i]=nex[j];
		}
		else j=nex[j];
	}
	return plen-j-1;
}
int main(){
	int maxn=0;
	rep(x,1,6)rep(y,1,6)rep(z,1,6){
		rep(i,1,200){
			rep(j,0,3){
				memset(vis,0,sizeof vis);
				int last=j^3;
				if(x>i)vis[0]=1;
				else vis[sg[x][y][z][i-x][0]]=1;
				while(last){
					if(lb(last)==1){
						if(y>i)vis[0]=1;
						else vis[sg[x][y][z][i-y][1]]=1;
					}
					else{
						if(z>i)vis[0]=1;
						else vis[sg[x][y][z][i-z][2]]=1;
					}
					last^=lb(last);
				}
				rep(k,0,5){
					if(!vis[k]){
						sg[x][y][z][i][j]=k;
						break;
					}
				}
			}
			int val=0;
			rep(j,0,3)val|=sg[x][y][z][i][j]<<(j*2);
			s[x][y][z][i]=val+1;
		}
		m[x][y][z]=solve(s[x][y][z]+100);
	}
	int t;
	scanf("%d",&t);
	while(t--){
		int n,x,y,z;
		scanf("%d%d%d%d",&n,&x,&y,&z);
		int SG=0;
		rep(i,0,n){
			scanf("%lld",&a[i]);
			if(a[i]>=100)a[i]=(a[i]-100)%m[x][y][z]+100;
		}
	//	cout<<"A\n";
		rep(i,0,n)SG^=sg[x][y][z][a[i]][0];
	//	cout<<SG<<"SG\n";
		if(!SG){
			printf("0\n\n");
			continue;
		}
		int ans=0;
		rep(i,0,n){
			int Sg=SG^sg[x][y][z][a[i]][0];
			if(x>a[i]){
				if(!Sg)++ans;
			}
			else{
				if(Sg==sg[x][y][z][a[i]-x][0])++ans;
			}
			if(y>a[i]){
				if(!Sg)++ans;
			}
			else{
				if(Sg==sg[x][y][z][a[i]-y][1])++ans;
			}
			if(z>a[i]){
				if(!Sg)++ans;
			}
			else{
				if(Sg==sg[x][y][z][a[i]-z][2])++ans;
			}
		}
		printf("%d\n\n",ans);
	}
}
/*
1
1 1 2 3
1
*/