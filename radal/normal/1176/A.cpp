#include <iostream>

using namespace std;

int main(){
	long int n;
	cin>>n;
	long long int j[n];
	//ong long int a[n];
	for (int i=0; i<n; i++){
		long long int x,t=0;
		cin>>x;
		if (x%2!=0 and x%3!=0 and x%5!=0 and x!=1){
			j[i]=-1;
			continue;
		}
		while (x!=1){
			t+=1;
			if (x%2==0){
				x=x/2;
				continue;
			}
			if (x%3==0){
				x=2*x/3;
				continue;
			}
			if (x%5==0){
				x=4*x/5;
				continue;
			}
			if (x%2!=0 and x%3!=0 and x%5!=0){
				t=-1;
				break;
			}
		}
		j[i]=t;
	}
	for (int i=0; i<n; i++){
		cout<<j[i]<<endl;
	}
}