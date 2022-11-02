#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<string>
#include<cstdlib>
#include<memory.h>
#include<ctime>

using namespace std;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int a[333][333];
int b[333][333];
pii c[666][333];
int nc[666];
int d[601][301][301];
int n;

const int inf = 1011111111;
const int maxn = 300;
int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n)REP(j,n) scanf("%d",&a[i][j]);
	CL(b,-1);
	REP(i,n)REP(j,n)if(b[i][j]==-1){
		b[i][j]=nc[i+j];
		c[i+j][nc[i+j]]=pii(i,j);
		nc[i+j]++;
	}

	REP(i,2*maxn)REP(j,maxn)REP(k,maxn) d[i][j][k] = -inf;
	d[0][0][0] = a[0][0];
	REP(i,2*n-2){
		int num = i + 1;
		if(num>n) num = 2*n-num;

		int val;
		REP(j,num)FOR(k,j,num)if((val=d[i][j][k])!=-inf){
			int _x1 = c[i][j].first;
			int _y1 = c[i][j].second;
			int _x2 = c[i][k].first;
			int _y2 = c[i][k].second;
			int x1,x2,y1,y2;
			REP(d1,2)REP(d2,2){
				x1=_x1;y1=_y1;x2=_x2;y2=_y2;
				if(d1) x1++; else y1++;
				if(d2) x2++; else y2++;
				if(x1>=n || y1>=n || y2>=n || x2>=n) continue;

				int nj = b[x1][y1];
				int nk = b[x2][y2];
				if(nj>nk) swap(nj,nk);
				d[i+1][nj][nk] = max(d[i+1][nj][nk], val + a[x1][y1] + a[x2][y2] - (x1==x2 && y1==y2 ? a[x1][y1] : 0));
			}
		}
	}
	cout<<d[2*n-2][0][0]<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",double(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}