#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=123;
int n, k;
char ans[5][maxn];
int main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
	cin>>n>>k;
	puts("YES");
	for(int i=1; i<=4; i++){
		for(int j=1; j<=n; j++)
			ans[i][j]='.';
	}
	if(k&1){
		if(k==1){
			ans[2][n/2+1]='#';
		}else if(k==3){
			ans[2][n/2]=ans[2][n/2+1]=ans[2][n/2+2]='#';
		}else{
			ans[2][2]=ans[3][2]='#';
			ans[2][3]='#';
			ans[2][4]=ans[3][4]='#';
			k-=5;
			for(int i=n-1; k>0; i--){
				ans[2][i]=ans[3][i]='#';
				k-=2;
			}
		}
	}else{
		for(int i=n-1; k>0; i--){
			ans[2][i]=ans[3][i]='#';
			k-=2;
		}
	}
	for(int i=1; i<=4; i++){
		for(int j=1; j<=n; j++){
			cout<<ans[i][j];
		}
		cout<<endl;
	}
	return 0;
}