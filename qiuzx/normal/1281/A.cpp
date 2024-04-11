#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define F first
#define S second
#define ll long long
using namespace std;
int main(){
	int T;
	string s;
	cin>>T;
	while(T--)
	{
		cin>>s;
		if(s[s.size()-1]=='o')
		{
			cout<<"FILIPINO"<<endl; 
		}
		else if(s[s.size()-1]=='u')
		{
			cout<<"JAPANESE"<<endl;
		}
		else if(s[s.size()-1]=='a')
		{
			cout<<"KOREAN"<<endl;
		}
	}
	return 0;
}