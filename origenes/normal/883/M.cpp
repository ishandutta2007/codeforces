#include <iostream>
using namespace std;
inline int ABS(int x){
	if(x==0) return 1;
	return x<0?-x:x;
}
int x1, y1, x2, y2;
int main(){
	cin>>x1>>y1>>x2>>y2;
	cout<<2*(ABS(x1-x2)+ABS(y1-y2)+2)<<endl;
	return 0;
}