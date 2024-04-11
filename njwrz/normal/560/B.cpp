#include <bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,x,y,z;
	cin>>a>>x;
	cin>>b>>y;
	cin>>c>>z;
	if(b<=a&&c<=a&&y<=x&&z<=x&&(b+c<=a||y+z<=x)){
		cout<<"YES";return 0;
	}
	swap(b,y);
	if(b<=a&&c<=a&&y<=x&&z<=x&&(b+c<=a||y+z<=x)){
		cout<<"YES";return 0;
	}
	swap(c,z);
	if(b<=a&&c<=a&&y<=x&&z<=x&&(b+c<=a||y+z<=x)){
		cout<<"YES";return 0;
	}
	swap(b,y);
	if(b<=a&&c<=a&&y<=x&&z<=x&&(b+c<=a||y+z<=x)){
		cout<<"YES";return 0;
	}
	cout<<"NO";
	return 0;
}