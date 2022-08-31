#include<iostream>

using namespace std;

typedef long long ll;
ll n,k,ans,tmp;

int main(){
	cin>>n>>k;
	if(k==1)
		cout<<n<<endl;
	else{
		for(int i=62;i>=0;i--){
			if((1ll<<i)<=n){
				tmp=i;
				break;
			}
		}
		cout<<(1ll<<(tmp+1))-1<<endl;
	}
	return 0;
}