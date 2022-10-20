#include <bits/stdc++.h>
using namespace std;
int main(){
	int m,l,r,k,i;
	string s,tl,tr,tem,nt,ot;
	cin>>s>>m;
	for(i=0;i<m;i++)
	{
		cin>>l>>r>>k;
		tl=s.substr(0,l-1);
		tr=s.substr(r);
		tem=s.substr(l-1,r-l+1);
		k%=tem.size();
		ot=tem.substr(0,tem.size()-k);
		nt=tem.substr(tem.size()-k);
		tem=nt+ot;
		s=tl+tem+tr;
	}
	cout<<s<<endl;
	return 0;
}