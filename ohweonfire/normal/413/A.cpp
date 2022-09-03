#include <iostream>
#include <algorithm>
using namespace  std;
int main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	int maxn,minn;
	maxn=0,minn=150;
	for(int i=0;i<b;i++){
			int x;
			cin>>x;
			maxn=max(maxn,x);
			minn=min(minn,x);
	}
	if(maxn>d||minn<c){cout<<"Incorrect";return 0;}
	if(a-b==1&&maxn<d&&minn>c){cout<<"Incorrect";return 0;}
	cout<<"Correct";
	return 0;
}