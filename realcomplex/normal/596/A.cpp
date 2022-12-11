#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	if(n==1){
		cout << -1;
		exit(0);
	}
	int x1,x2,y1,y2;
	x1 = INT_MAX,x2=INT_MIN,y1=INT_MAX,y2=INT_MIN;
	int w,h;
	for(int j= 0;j<n;j++){
		cin >> w >> h;
		x1 = min(x1,w);
		x2 = max(x2,w);
		y1 = min(y1,h);
		y2 = max(y2,h);
	}
	if((x2-x1)*(y2-y1)==0)cout << -1;
	else cout << (x2-x1)*(y2-y1);
	cout << "\n";
	return 0;
}