#include<iostream>
using namespace std;
int a[4];
int ans[6];
int num[6] = {4,8,15,16,23,42};
void f(int *x,int a12,int a13){
	int p;
	for(int i = 0;i < 6;++i){
		int ok = 0;
		for(int j = 0;j < 6;++j){
			if(i == j) continue;
			if(num[i]*num[j] == a12 || num[i]*num[j] == a13) ok++;
		}
		if(ok == 2) {
			p = i;break;
		}
	}
	x[0] = num[p];
	x[1] = a12/num[p];
	x[2] = a13/num[p];
}
int main(){
	int x,y;
	cout<<"? 1 2"<<endl<<flush;
	cin>>x;
	cout<<"? 1 3"<<endl<<flush;
	cin>>y;
	f(ans,x,y);
	cout<<"? 4 5"<<endl<<flush;
	cin>>x;
	cout<<"? 4 6"<<endl<<flush;
	cin>>y;
	f(ans+3,x,y);
	cout<<"! ";
	cout<<ans[0];
	for(int i = 1;i < 6;++i) cout<<" "<<ans[i];
	cout<<endl<<flush;
	
}