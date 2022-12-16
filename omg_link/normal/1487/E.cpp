#include <stdio.h>
#include <vector>
#include <set>
#define MN 150000

int n[4];
int a[4][MN+5];
int f[4][MN+5];
std::vector<int> e[4][MN+5];

int main(){
	for(int i=0;i<4;i++)
		scanf("%d",&n[i]);
	for(int i=0;i<4;i++)
		for(int j=1;j<=n[i];j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=3;i++){
		int m,x,y;
		scanf("%d",&m);
		for(int j=1;j<=m;j++){
			scanf("%d%d",&x,&y);
			e[i][y].push_back(x);
		}
	}
	for(int i=1;i<=n[0];i++)
		f[0][i] = a[0][i];
	for(int i=1;i<=3;i++){
		std::multiset<int> s;
		for(int j=1;j<=n[i-1];j++){
			s.insert(f[i-1][j]);
		}
		for(int j=1;j<=n[i];j++){
			for(auto v:e[i][j])
				s.erase(s.find(f[i-1][v]));
			if(s.empty())
				f[i][j] = 0x3fffffff;
			else
				f[i][j] = a[i][j] + *s.begin();
			for(auto v:e[i][j])
				s.insert(f[i-1][v]);
		}
	}
	int ans = 0x3fffffff;
	for(int i=1;i<=n[3];i++)
		ans = std::min(ans,f[3][i]);
	printf("%d\n",ans>=0x3fffffff?-1:ans);
}