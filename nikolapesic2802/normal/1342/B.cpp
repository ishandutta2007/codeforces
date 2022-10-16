#include <bits/stdc++.h>
using namespace std;
main()
{
	int t;
	cin>>t;
	while(t--){
		string s,a;
		cin>>s;
		for(auto p:s)
			a+="01";
		if(s.find('0')==string::npos||s.find('1')==string::npos)
			cout << s << endl;
		else
			cout << a << endl;
	}
}