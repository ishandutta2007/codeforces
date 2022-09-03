#include <bits/stdc++.h>
using namespace std;
const int maxn=2005;
int ans[maxn];
char field[maxn][maxn];
int main(){
	int n,m,k;
scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;i++){
			scanf("%s",field[i]);
			if(i==0)continue;
			for(int j=0;j<m;j++){
					if(field[i][j]=='.')continue;
					if(field[i][j]=='D')continue;
					if(field[i][j]=='U'&&(i%2)==0){
										 ans[j]++;
					}
					if(field[i][j]=='L'){
										 if(j-i<0)continue;
										 ans[j-i]++;
					}
					if(field[i][j]=='R'){
										 if(i+j>=m)continue;
										 ans[i+j]++;
					}
			}
	}
	for(int i=0;i<m;i++)cout<<ans[i]<<' ';
	//system("pause");
	return 0;
}