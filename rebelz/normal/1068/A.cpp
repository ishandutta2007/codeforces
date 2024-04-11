#include<bits/stdc++.h>

using namespace std;

long long n,m,k,l;

int main(){
	cin>>n>>m>>k>>l;
	if(((k+l-1)/m+1)*m>n)
		cout<<-1<<endl;
	else
		cout<<(k+l-1)/m+1<<endl;
	return 0;
}