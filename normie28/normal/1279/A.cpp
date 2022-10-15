#include <bits/stdc++.h>
using namespace std;
 #define MOD 1000000007
 #define A '@'
 #define B '*'
 #define C '#'
 #define max(a,b) ((a>b)?a:b)
 #define endl "\n"
 struct node {int l; int r; int ln; int rn; int a;};
 
vector<node> st;
 
 
long long t,k,n,m, i,j,mid,a,b,c;
int main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   cin>>t;
   for (k=1;k<=t;k++)
   {
   	cin>>a>>b>>c; n=a+b+c;
   	if ((a+b>=n/2)and(b+c>=n/2)and(c+a>=n/2)) cout<<"Yes"; else cout<<"No";
   	cout<<endl;
   }
}