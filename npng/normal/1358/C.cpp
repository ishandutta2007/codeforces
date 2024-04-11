#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int x_1,y_1,x_2,y_2;
		scanf("%d%d%d%d",&x_1,&y_1,&x_2,&y_2);
		ll ans=1ll*(x_2-x_1)*(y_2-y_1);
		ans++;
		cout<<ans<<endl;
	}
	return 0;
}