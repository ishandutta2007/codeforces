#include <stdio.h>
#include <bitset>
#include <vector>

using namespace std;
bitset<2000> a[2000];
bitset<2000> ai[2000];
pair<int,int> p[500000];
int main(){
	int n,m;scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int a,b;scanf("%d%d",&a,&b);a--;b--;
		p[i]=make_pair(a,b);
		::a[a][b] = 1;
	}
	for(int i=0;i<n;i++)ai[i][i] = 1;
	for(int i=0;i<n;i++){
		int j;
		for(j=i;j<n;j++){
			if(a[j][i]==1)break;
		}
		swap(a[i],a[j]);swap(ai[i],ai[j]);
		for(int j=i+1;j<n;j++){
			if(a[j][i]==1){
				a[j] ^= a[i];
				ai[j] ^= ai[i];
			}
		}
	}
	for(int i= n-1;i>=0;i--){
		for(int j=i-1;j>=0;j--){
			if(a[j][i]==1){
				a[j] ^= a[i];
				ai[j] ^= ai[i];
			}
		}
	}
	for(int i=0;i<m;i++){
		int x =p[i].first; int y=p[i].second;
		if(ai[y][x]==1)puts("NO");
		else puts("YES");
	}
}