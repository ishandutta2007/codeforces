#include <iostream>
#include <algorithm>
#define sqr(x) (x)*(x)
using namespace std;
int p[]={0,1,2,3,4,5,6,7,8};
int x[9],y[9];
int dist(int i,int j){
	return sqr(x[p[i]]-x[p[j]])+sqr(y[p[i]]-y[p[j]]);
}
int main(){
	for(int i=1;i<=8;i++)cin>>x[i]>>y[i];
	do{
	   	if(!(dist(1,2)==dist(2,3)&&dist(2,3)==dist(3,4)&&dist(3,4)==dist(4,1)&&
		   dist(1,3)==dist(2,4)))continue;
	   	if(!(dist(5,6)==dist(7,8)&&dist(5,8)==dist(6,7)&&dist(6,8)==dist(5,7)))continue;
	   	cout<<"YES\n";
	   	for(int i=1;i<=8;i++){
				cout<<p[i]<<' ';
				if(i%4==0)cout<<endl;
		}
		return 0;
	}while(next_permutation(p+1,p+9));
	cout<<"NO\n";
	return 0;
}