#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <cctype>
using namespace std;
int64_t i,cur,minh,t,n,m,k,count,err=0,drop[10001],hit[10001],loc[10001]; string s="";
int intr(int64_t no) {
	int64_t sud,sbox;
	sbox=no; sud=0;
	while (sbox!=0) {sud+=sbox%10; sbox/=10;}
	if (sud%4==0) return 1; else return 0; 
} 
int main()
{ 
	cin>>n;
	cur=n;
	while (!intr(cur)) cur++;
	cout<<cur;
}