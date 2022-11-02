#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

int n,m,k;
const int MAXN = 1000+5;
int a[MAXN][MAXN];
int row[MAXN],col[MAXN];

int main(){
	scanf("%d%d%d",&n,&m,&k);
	FOR(i,1,n) row[i] = i;FOR(i,1,m) col[i]  =i;
	FOR(i,1,n) FOR(j,1,m) scanf("%d",&a[i][j]);
	FOR(i,1,k){
		char str[23];int x,y;scanf("%s",str+1);scanf("%d%d",&x,&y);
		if(str[1] == 'c'){
			std::swap(col[x],col[y]);
		}
		if(str[1] == 'r'){
			std::swap(row[x],row[y]);
		}
		if(str[1] == 'g'){
			printf("%d\n",a[row[x]][col[y]]);
		}
	}
	return 0;
}