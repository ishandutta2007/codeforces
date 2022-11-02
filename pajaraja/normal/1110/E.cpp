#include <bits/stdc++.h>
#define MAXN 100007
using namespace std;
int r[MAXN],k[MAXN],c[MAXN],t[MAXN];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>c[i];
	for(int i=0;i<n;i++) cin>>t[i];
	for(int i=0;i<n-1;i++) k[i]=(c[i+1]-c[i]);
	for(int i=0;i<n-1;i++) r[i]=(t[i+1]-t[i]);
	sort(k,k+n-1); sort(r,r+n-1);
	if(t[0]!=c[0] || t[n-1]!=c[n-1]) {printf("No"); return 0;}
	for(int i=0;i<n;i++) if(r[i]!=k[i]) {printf("No"); return 0;}
	printf("Yes"); 
}