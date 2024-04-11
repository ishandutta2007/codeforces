#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define INF 10000000000000001
const int MAX_N = 200010;
long long a[2006],res,t=INF;
float temp;
string mineq(string a)
{
if (a.length()%2) return a;
string aa=mineq(a.substr(0,a.length()/2));
string bb=mineq(a.substr(a.length()/2,a.length()/2));
if (aa<bb) return aa+bb; else return bb+aa;
}
int main() {

	long long i,k,j,n,x,y,z;
	string s1,s2;
	cin>>s1>>s2;
	if (mineq(s1)==mineq(s2)) cout<<"YES"; else cout<<"NO";
}