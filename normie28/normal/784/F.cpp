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
vector <ll> a;
/*********FUNCTIONS**************/
 
 
/***********MAIN**************/
 
int main(void) 
{
	cin>>n;
	for (i=1;i<=n;i++) {cin>>b; a.push_back(b);}
	sort (a.begin(),a.end());
	for (i=0;i<2000000000;i++) j*=2;
	for (i=0;i<n;i++) cout<<a[i]<<' ';
}