#include <bits/stdc++.h>
using namespace std;
int a[105][105];
vector <int> ans1,ans2;
int main(){
	int n;
	char c[105][105];
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)cin>>c[i][j];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(c[i][j]=='.'){
				for(int k=1;k<=n;k++){
					a[i][k]++;a[k][j]++;
				}
				a[i][j]--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(!a[i][j]){
				cout<<-1;return 0;
			}
			if(c[i][j]=='.'){
				bool f=1;
				for(int k=1;k<=n;k++){
					if(a[i][k]<2||
						a[k][j]<2){
						f=0;break;
					}
				}
				if(f){
					for(int k=1;k<=n;k++){
						a[i][k]--;a[k][j]--;
					}
					a[i][j]++;
				}else{
					ans1.push_back(i);
					ans2.push_back(j);
				}
			}
		}
	}
	for(int i=0;i<ans1.size();i++){
		cout<<ans1[i]<<' '<<ans2[i]<<'\n';
	}
	return 0;
}