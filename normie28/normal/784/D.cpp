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
struct sol {ll val; ll lis;};
/******************************/
string expr;
ll i,j,b,used[50],n,m,res,path[50],hol,map[50][50],x,y;
vector <ll> a;
string s;
/*********FUNCTIONS**************/
void tri (ll las, ll cur)
{
	if (cur==m) { cout<<'(';for (ll ii=1;ii<=m;ii++) {cout<<path[ii];  if (ii!=m) cout<<',';}
	cout<<')'<<endl; res++; return;}
	for (ll ii=1;ii<=n;ii++) if ((map[las][ii]==1)and(!used[ii])) {path[cur+1]=ii; used[ii]=1; tri(ii,cur+1); used[ii]=0; path[cur+1]=0;}
}
/***********MAIN**************/

int main()
{
	cin>>s;
	n=s.length();
	for (i=0;i<=n/2;i++) if (((s[i]=='3')and(s[n-1-i]=='3'))or((s[i]=='7')and(s[n-1-i]=='7'))or((s[i]=='4')and(s[n-1-i]=='6'))or((s[i]=='6')and(s[n-1-i]=='4'))or((s[i]=='5')and(s[n-1-i]=='9'))or((s[i]=='9')and(s[n-1-i]=='5'))or((s[i]=='0')and(s[n-1-i]=='8'))or((s[i]=='8')and(s[n-1-i]=='0'))); else {cout<<"No"; return 0;}
	cout<<"Yes";
}