#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int a[5],b,c;

int main()
{
	cin>>a[1]>>a[2]>>a[3];
	sort(a+1,a+3+1);
	cout<<a[3]-a[1];
}