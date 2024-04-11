#include <bits/stdc++.h>
using namespace std;
int x;
bool check(int p){
	p=(p<<1)-1;
	p=(p/2+1)*(p/2+1)+(p/2)*(p/2);
	return (p>=x);
}
int main(){
	cin>>x;
	if(x==3){cout<<5;return 0;}
	int l=1,r=50;
	while(r-l>5){
		int m=(l+r)>>1;
		if(check(m)){
			r=m;
		}else l=m+1;
	}
	for(int i=l;i<=r;i++)if(check(i)){cout<<i*2-1;return 0;}
	return 0;
}