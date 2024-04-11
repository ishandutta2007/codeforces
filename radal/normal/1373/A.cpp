#include<bits/stdc++.h> 
using namespace std;  
int main(){
	long long int t;
	cin >> t;
	for (int p=0; p<t; p++){
		long long int a,b,c,ans1=0,ans2=0;
		cin >> a >> b >> c;
		if (a >= c) ans1=-1;
		if (a*b <= c) ans2=-1;
		if (ans1 != -1) ans1=1;
		if (ans2 != -1) ans2=b;
		cout<<ans1<<" "<<ans2<<endl;
	}
}