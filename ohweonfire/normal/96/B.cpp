#include <iostream>
using namespace std;
typedef long long ll;
ll n;
ll ans=-1;
void dfs(ll now,int a,int b){
	 if(now>n*100)return;
	 if(now>=n&&a==b)if(ans==-1||now<ans)ans=now;
	 dfs(now*10+4,a+1,b);
	 dfs(now*10+7,a,b+1);
}
int main(){
	cin>>n;
	dfs(0,0,0);
	cout<<ans<<endl;
	//system("pause");
	return 0;
}