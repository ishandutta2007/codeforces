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
	long double sum=0,nn=n,x,y;
	for (i=1;i<=n;i++) {cin>>x>>y; sum+=y;}
	
	sum/=nn;
	sum+=5;
	cout<<fixed<<setprecision(10)<<sum;
}