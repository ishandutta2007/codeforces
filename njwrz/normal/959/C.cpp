#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
	cin>>n;
	if(n<6){
		cout<<-1<<'\n';
		for(int i=1;i<n;i++)cout<<"1 "<<i+1<<'\n';
		return 0;
	}
	cout<<"1 2\n1 3\n1 4\n2 5\n2 6\n";
	for(int i=7;i<=n;i++)cout<<"2 "<<i<<'\n';
	for(int i=1;i<n;i++)cout<<"1 "<<i+1<<'\n';
    return 0;
}