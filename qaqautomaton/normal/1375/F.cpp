/*
Author: QAQAutomaton
Lang: C++
Code: F.cpp
Mail: lk@qaq-am.com
Blog: https://www.qaq-am.com/
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[4];
ll b[4];
void make(ll x){
	cout<<x<<endl;
	int y;
	cin>>y;
	a[y]+=x;
}
signed main(){
	cin>>a[1]>>a[2]>>a[3];
	cout<<"First"<<endl;
	make(10000000000ll);
	for(int i=1;i<=3;++i)b[i]=a[i];
	sort(b+1,b+4);
	make((b[3]-b[2])*2+(b[2]-b[1]));
	sort(a+1,a+4);
	cout<<a[2]-a[1]<<endl;
	return 0;
}