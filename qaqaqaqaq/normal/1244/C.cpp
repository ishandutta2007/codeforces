#include<bits/stdc++.h>
using namespace std;
 
long long w,p,d,n,y;
bool ck(long long x){
    if (x<0) return 0;
	y=(p-w*x)/d;
	if (y<0||w*x+y*d!=p) return 0;
	if (x+y>n) return 0;
	return 1;
}
 
int main(){
	cin>>n>>p>>w>>d;
	long long x=p/w;
	for (int j=0;j<d;++j){
		if (ck(x-j)){
			cout<<x-j<<" "<<y<<" "<<n-x-y+j<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}