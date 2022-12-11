#include <bits/stdc++.h>

using namespace std;

int x,y;

bool can(int m){
	if(m==0){
		if(x>=2&&y>=2){
			x-=2;
			y-=2;
			return true;
		}
		else if(x>=1&&y>=12){
			x-=1;
			y-=12;
			return true;
		}
		else if(y>=22){
			y-=22;
			return true;
		}
		else return false;
	}	
	else{
		if(y>=22){
			y-=22;
			return true;
		}
		else if(x>=1&&y>=12){
			x--;
			y-=12;
			return true;
		}
		else if(x>=2&&y>=2){
			x-=2;
			y-=2;
			return true;
		}
		else{
			return false;
		}
	}
}

int main(){
	cin >> x >> y;
	int k = 0;
	while(can(k)){
		k = 1-k;
	}
	if(k==1)cout << "Ciel";
	else cout << "Hanako";
	cout << "\n";
	return 0;
}