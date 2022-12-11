#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 2550;
int a[maxn][maxn]={0},b[maxn][maxn]={0};
int c1[maxn],c2[maxn];
int cnt;
int main(){
	int n,m;cin>>n>>m;
	for(int i = 0;i < n;++i) for(int j = 0;j < m;++j) scanf("%d",&a[i][j]);
	for(int i = 0;i < n;++i) for(int j = 0;j < m;++j) scanf("%d",&b[i][j]);
	int ok = 1;
	for(int s = 0;s < n + m - 1;++s){
		if(!ok) break;
		cnt = 0;
		for(int i = 0;i <= s;++i){
			c1[cnt] = a[i][s-i];
			c2[cnt] = b[i][s-i];
			cnt++;
		}
		sort(c1,c1+cnt);sort(c2,c2+cnt);
		for(int i = 0;i < cnt;++i) {
			if(c1[i]!=c2[i]) {
				
				ok = 0;break;
			}
		}
	}
	if(ok) printf("YES\n");
	else printf("NO\n");
}