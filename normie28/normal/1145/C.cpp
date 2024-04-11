// Thanks to robs77 for this template
/***********HEADER***************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
/***********MACROS***************/
//#define int long long
#define inf 100000000000000000 
#define ll  long long 

/*********VARIABLE****************/
using namespace std;
typedef pair<ll,ll> ii;
/******************************/
string s,res;
ll n,i,j,b,row[100001],col[100001];

/*********FUNCTIONS**************/


/***********MAIN**************/

int main(void) 
{
	cin>>n;
	if (n==0) cout<<15;
	if (n==1) cout<<14;
	if (n==2) cout<<12;
	if (n==3) cout<<13;
	if (n==4) cout<<8;
	if (n==5) cout<<9;
	if (n==6) cout<<10;
	if (n==7) cout<<11;
	if (n==8) cout<<0;
	if (n==9) cout<<1;
	if (n==10) cout<<2;
	if (n==11) cout<<3;
	if (n==12) cout<<4;
	if (n==13) cout<<5;
	if (n==14) cout<<6;
	if (n==15) cout<<7;
}