#include <bits/stdc++.h>

using namespace std;

int n,x;
int is(int t){
	for(int j = 1;j<=n;j++){
		if(j%2==1){
			if(t==1)t = 0;
			else if(t==0)t = 1;
		}
		else{
			if(t==2)t = 1;
			else if(t == 1)t = 2;
		}
	}
	return t;
}
int main(){
	cin >> n >> x;
	n%=6;
	if(is(0)==x)cout << 0 << endl;
	else if(is(1)==x)cout << 1 << endl;
	else cout << 2 << endl;
	return 0;
}