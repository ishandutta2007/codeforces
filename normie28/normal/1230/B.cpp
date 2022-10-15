#include <iostream>
#include <string>
using namespace std;
#define ll long long
ll a,b,n,m,i,j,c,d;
string s;
int main()
{
    cin>>n>>m;
    cin>>s;
	if (n==1) {if (m==0) cout<<s; else cout<<0; return 0;} 
    i=0;
    while ((m>0)and(i<n)) {if (((s[i]=='1')and(i==0))or(s[i]=='0'))  i++; else {if (i==0) s[i]='1'; else s[i]='0'; m--;} }
    cout<<s;
}