#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,i,j,maxx=0,a=0,b=0,c=0;
string s,t;
int l[200001],r[200001];
signed main() {
	cin>>s>>t;
	n=s.length();
	if (n<5) {cout<<"Too weak"; return 0;}
	for (i=0;i<n;i++)
	{
	if ((s[i]>=48)and(s[i]<=57)) a=1;
	if ((s[i]>=65)and(s[i]<=90)) b=1;
	if ((s[i]>=97)and(s[i]<=122)) c=1;
	}
	if (a*b*c) cout<<"Correct"; else cout<<"Too weak";
}