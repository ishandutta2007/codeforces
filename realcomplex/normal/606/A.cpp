#include <bits/stdc++.h>

using namespace std;

int main(){
	int a,b,c;
	int x,y,z;
	cin >> a >> b >> c;
	cin >> x >> y >> z;
	int l = max(0,(c-z)/2);
	l += max((b-y)/2,0);
	l += max(0,(a-x)/2);
	if(a<x)l-=x-a;
	if(b<y)l-=y-b;
	if(z>c)l-=z-c;
	if(l>=0)cout << "Yes\n";
	else cout << "No\n";
	return 0;
}