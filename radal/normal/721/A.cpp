#include <iostream>
using namespace std;
int main(){
	int t,n=0;
	bool B=0;
	cin>>t;
	string a;
	cin>>a;
	for (int i=0; i<t; i++){
		if (a[i]=='B'){
			n+=1;
			while (a[i]=='B' and i<t){
				i+=1;
			}
		}
	}
	long long int j[n];
	int k=-1;
	for (int i=0; i<t; i++){
		int r=0;
		if (a[i]=='B'){
			k+=1;
			while (a[i]=='B' and i<t){
				r+=1;
				i+=1;
				
			}
			j[k]=r;
		}
	}
	cout<<n<<endl;
	for (int i=0; i<n; i++){
		cout<<j[i]<<' ';
	}	
}