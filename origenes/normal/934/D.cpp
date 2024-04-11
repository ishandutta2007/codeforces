#include <iostream>
using namespace std;
typedef long long ll;
const int maxn=2134;
ll p, k, a[maxn], degs;
int main(){
	cin>>p>>k;
	while(p){
		if(p%k>=0){
			a[degs++]=p%k;
			p=-p/k;
		}else{
			a[degs++]=k+p%k;
			p=-p/k+1;
		}
	}
	cout<<degs<<endl;
	for(int i=0; i<degs; i++)
		cout<<a[i]<<' ';
	cout<<endl;
	return 0;
}