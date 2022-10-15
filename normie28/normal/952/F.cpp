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
ll i,j,b,used[50],n,m,res,path[50],hol,map[50][50];
vector <ll> a;
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
	cin>>expr;
long long result = 0, cur = 0;
expr += "+";
int sign = +1;
for (char c : expr) {
    if (c == '+' || c == '-') {
        result += sign * cur;
        cur = 0;
    }
    if (c == '-')
        sign = -1;
    if (c == '+')
        sign = +1;
    cur = cur * 10 + (c - '0');
}
	cout<<result;
}