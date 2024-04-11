#include <iostream>
#include <iomanip>
using namespace std;
typedef long long ll;
int main(){
	cout<<fixed<<setprecision(10);
	int n, m;
	cin>>n>>m;
	double p=1e20;
	for(int i=0; i<n; i++){
		double a, b;
		cin>>a>>b;
		double cur=a/b;
		p=min(cur, p);
	}
	cout<<m*p<<endl;
	return 0;
}