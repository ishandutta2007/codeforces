#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b)for(int i=(a),i##_end_=(b);i<i##_end_;++i)
#define PER(i,a,b)for(int i=(b)-1,i##_end_=(a);i>=i##_end_;--i)
#define pb push_back
template<class T>inline bool umx(T& A,const T& B){return A<B?A=B,1:0;}
template<class T>inline bool umn(T& A,const T& B){return A>B?A=B,1:0;}
typedef pair<int,int> PII;
typedef double db;
typedef pair<db,int> PDI;
typedef long long LL;

const int maxn=1010;

int dxy[4][2]={{1,0},{0,-1},{0,1},{-1,0}};
char cxy[4]={'D','L','R','U'};

int n,m,k;
char mp[maxn][maxn];

PII q[maxn*maxn];int l,r;
int d[maxn][maxn];
PII s;

bool check(int x,int y){return 0<=x && x<n && 0<=y && y<m && mp[x][y]!='*';}
void bfs(){
	memset(d,0xff,sizeof d);
	l=r=0;q[r++]=s;d[s.first][s.second]=0;
	for(;l!=r;++l){
		PII u=q[l];
		for(int dir=0;dir<4;++dir){
			PII v=(PII){u.first+dxy[dir][0],u.second+dxy[dir][1]};
			if(check(v.first,v.second) && d[v.first][v.second]==-1){
				d[v.first][v.second]=d[u.first][u.second]+1;
				q[r++]=v;
			}
		}
	}
}
string res;
bool go(){
	PII u=s;
	for(;k;){
		bool ok=0;
		for(int dir=0;dir<4;++dir){
			PII v=(PII){u.first+dxy[dir][0],u.second+dxy[dir][1]};
			if(check(v.first,v.second) && d[v.first][v.second]<=k-1){
				res+=cxy[dir];
				u=v;
				ok=1;
				--k;
				break;
			}
		}
		if(!ok)return 0;
	}
	return 1;
}
int main(){
//	freopen("in.txt","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	REP(i,0,n)REP(j,0,m){
		char c;scanf(" %c",&c);
		if(c=='X'){
			s=PII(i,j);
			c='.';
		}
		mp[i][j]=c;
	}
	bfs();
	if(k&1){puts("IMPOSSIBLE");return 0;}
	res="";
	if(!go())puts("IMPOSSIBLE");else puts(res.c_str());
	return 0;
}