#include<bits/stdc++.h>
using namespace std;
 #define map mapp
 #define endl "\n"
const int mx=2005;
int x[mx], y[mx], map[201][201], dx, dy, l, xx, yy;
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n; cin>>n;
	for (int i=1;i<=n;i++) {cin>>x[i]>>y[i]; map[x[i]+100][y[i]+100]=1;}
	long long res=0;
	for (int i=1;i<n;i++)
	for (int j=i+1;j<=n;j++)
	{
		res+=n+1;
		dx=x[j]-x[i];
		dy=y[j]-y[i];
		l=__gcd(dx,dy);
		dx/=l;
		dy/=l;
		xx=x[i];
		yy=y[i];
		while ((xx<=100)and(yy<=100)and(xx>=-100)and(yy>=-100)) {res-=map[xx+100][yy+100]; xx+=dx; yy+=dy;}
		xx=x[i];
		yy=y[i];
		while ((xx<=100)and(yy<=100)and(xx>=-100)and(yy>=-100)) {res-=map[xx+100][yy+100]; xx-=dx; yy-=dy;}
	}
	cout<<res/3;
}