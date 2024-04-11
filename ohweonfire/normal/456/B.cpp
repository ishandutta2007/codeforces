#include <iostream>
using namespace std;
int ans[]={4,0,0,0};
string tmp;
int main()
{
	cin>>tmp;
	int a=0;
	if(tmp.size()<2)
		a=tmp[0]-'0';
	else
		a=tmp[tmp.size()-1]-'0'+(tmp[tmp.size()-2]-'0')*10;
	a%=4;
	cout<<ans[a];
	return 0;
}