#include <iostream>
 
using namespace std;
int main(){
	int c_4=0,c_3=0,c_2=0,c_1=0;
	int n;
	bool done=1;
	int t=0;
	cin>>n;
	for (int i=0; i<n; i++){
		int x;
		cin>>x;
		if (x==4){
			c_4+=1;
		}
		if (x==3){
			c_3+=1;
		}
		if (x==2){
			c_2+=1;
		}
		if (x==1){
			c_1+=1;
		}
	}
	t+=c_4+c_3;
	if (c_3>=c_1){
		c_1=0;
	}
	else{
		c_1-=c_3;
	}
	t+=c_2/2;
	if (c_2%2==1){
		if (c_1>=2 and done){
			t+=1;
			c_2-=1;
			c_1-=2;
			done=0;
		}
		if (c_1==1 and done){
			t+=1;
			c_2-=1;
			c_1-=1;
			done=0;
		}
		if (c_1==0 and done){
			t+=1;
			c_2-=1;
			done=0;
		}
	}
	//cout<<c_1;
	t+=c_1/4;
	if (c_1%4!=0){
		t+=1;
	}
	cout<<t;
    return 0;
}