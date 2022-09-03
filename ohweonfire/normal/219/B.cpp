#include <iostream>
#include <string.h>
using namespace std;
typedef long long ll;
ll p,d;
int main(){
	cin>>p>>d;
	for(int i=18;i>=0;i--){
			ll sum=0;
			for(int j=0;j<i;j++)sum=sum*10+9;
			ll ans=(p-sum)/(sum+1)*(sum+1)+sum;
			if(ans<=p&&p-ans<=d){
					  cout<<ans<<endl;
					  //system("pause");
					  return 0;
			}
	}
	return 0;
}