#include <bits/stdc++.h>
using namespace std;
int main(){
	long long w1,h1,w2,h2,num=0;
	cin>>w1>>h1>>w2>>h2;
	num+=w1*2;
	num+=(h1+h2)*2;
	num+=4;
	cout<<num<<endl;
	return 0; 
}