#include <stdio.h>
#include <algorithm>
#define MN 10
#define MM 10000

using std::min,std::max;
using std::abs;
using std::sort;

int n,m,x[MN],p[MM];
char c[MN][MM+5];

int solve(int S){
	static int pRate[MM],id[MM];
	for(int i=0;i<m;i++){
		pRate[i] = 0;
		id[i] = i;
	}
	for(int i=0;i<n;i++){
		int sc = (S&(1<<i))?1:-1;
		for(int j=0;j<m;j++)
			if(c[i][j]=='1')
				pRate[j] += sc;
	}
	sort(id,id+m,[](int x,int y)->bool{
		return pRate[x]<pRate[y];
	});
	for(int i=0;i<m;i++)
		p[id[i]] = i+1;
	int ans = 0;
	for(int i=0;i<n;i++){
		int score = 0;
		for(int j=0;j<m;j++){
			if(c[i][j]=='1'){
				score += p[j];
			}
		}
		ans += abs(score-x[i]);
	}
	return ans;
}

void solve(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",&x[i]);
	for(int i=0;i<n;i++)
		scanf("%s",&c[i][0]);
	int ans = -1;
	int ansS = 0;
	for(int S=0;S<(1<<n);S++){
		int score = solve(S);
		if(score>ans){
			ans = score;
			ansS = S;
		}
	}
	solve(ansS);
	for(int i=0;i<m;i++)
		printf("%d%c",p[i]," \n"[i==m-1]);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}