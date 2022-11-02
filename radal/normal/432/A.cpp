#include <iostream>
 
using namespace std;
int a[2000];
int main()
{
	int k,n,t=0;
	cin>>n>>k;
	for (int i=0; i<n; i++){
		int x;
		cin>>x;
		if (x<=5-k){
			a[t]=x;
			t+=1;
		}
	}
	cout<<t/3;
    return 0;
}