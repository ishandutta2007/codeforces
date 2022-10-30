#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;
vector<int> sol;
int main(int argc, char** argv) 
{
	int n,t=0;
	string s;
	cin>>n;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='B') t++;
		else if(t>0)
		{
			sol.push_back(t);
			t=0;
		}
	}
	if(t!=0) sol.push_back(t);
	int k=sol.size();
	cout<<k<<endl;
	for(int i=0;i<sol.size();i++) cout<<sol[i]<<" ";
	return 0;
}