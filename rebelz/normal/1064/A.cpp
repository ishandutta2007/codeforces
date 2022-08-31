#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int a,b,c;

int main(){
	cin>>a>>b>>c;
	if(a>b)
		swap(a,b);
	if(a>c)
		swap(a,c);
	if(b>c)
		swap(b,c);
	cout<<max(0,c-b-a+1)<<endl;
	return 0;
}