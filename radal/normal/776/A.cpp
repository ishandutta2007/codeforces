#include <iostream>
using namespace std;
int main(){
	int n;
	string a,b;
	cin>>a>>b;
	cin>>n;
	string ans[n+1][2];
	ans[0][0]=a;
	ans[0][1]=b;
	for (int i=1; i<=n; i++){
		string A,B;
		cin>>A>>B;
		if (A==a){
			a=B;
			ans[i][0]=a;
			ans[i][1]=b;
		}
		if (A==b){
			b=B;
			ans[i][0]=a;
			ans[i][1]=b;
		}
	}
	for (int i=0; i<=n; i++){
		cout<<ans[i][0]<<' '<<ans[i][1]<<endl;
	} 
}