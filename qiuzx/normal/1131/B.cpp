#include <bits/stdc++.h>
using namespace std;
int main(){
	int nowa=0,nowb=0,preva=-1,prevb=-2;
	int i,n,draw=1;
	bool flag=true;
	cin>>n;
	for(i=0;i<n;i++)
	{
		if(flag)
		{
			preva=nowa;
			prevb=nowb;
		}
		cin>>nowa>>nowb;
		if(nowa==preva&&nowb==prevb)
		{
			flag=false;
			continue;
		}
		else if(preva==prevb)
			draw+=max(0,min(nowa,nowb)-max(preva,prevb));
		else
			draw+=max(0,min(nowa,nowb)-max(preva,prevb)+1);
		flag=true;
	}
	cout<<draw<<endl;
	return 0;
}