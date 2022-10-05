#include <iostream>
using namespace std;
int a[24],b[3][8]={
	{1,3,5,7,9,11,22,20},
	{2,3,16,18,9,8,15,13},
	{14,15,6,7,18,19,22,23}
};
void c(){
	for(int i=0;i<24;i++)
		if(a[i]!=a[i/4*4])return;
	cout<<"YES",exit(0);
}
void r(int t,int m){
	for(int x=0;x<2*m;x++)
		for(int i=0;i<7;i++)
			swap(a[b[t][i]],a[b[t][i + 1]]);
}
int main(){
	for(int i=0;i<24;i++)cin>>a[i];
	r(0,1),c(),r(0,2),c(),r(0,1);
	r(1,1),c(),r(1,2),c(),r(1,1);
	r(2,1),c(),r(2,2),c();
	cout<<"NO";
}