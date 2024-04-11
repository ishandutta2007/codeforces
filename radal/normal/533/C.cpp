#include <bits/stdc++.h>
#define ll long long int 
#define rep(i,l,r) for(int i=l; i<r; i++)
#define repr(i,r,l) for(int i=r; i>=l; --i)
using namespace std; 

const int N=2e5; 
ll b[N];
int main(){
	ll x1,y1,x2,y2,t=0;
	cin >> x1 >> y1 >> x2 >> y2;
	while ((x1 || y1) && (x2 || y2)){
		//cout << "x1 : " << x1 << " y1 :"<<y1 <<endl;
		//cout << "x2 : " << x2 << " y2 :"<<y2 <<endl;
		
		if (!(t%2)){
			if ((x1 == 0 && y1 - 1 == 0) || (y1 == 0 && x1-1 == 0)){
				y1 = 0;
				x1 = 0;
				break;
			}
			if ((x2 ==0 && x1 == 0 && y1-1 == y2) || (y1 == 0 && y2 == 0 && x1-1 == x2)){
		//		cout << "egr"<<endl;
				t++;
				continue;
			}
			
			if ((x1 - 1 == x2 && y1 == y2)){
				if (y1) y1--;
				t++;
				continue;
			}

			if (y1 - 1 == y2 && x1 == x2){
				if (x1) x1--;
				t++;
				continue;
			}
			
			if ((x1 && (y1 < y2 - (x2 - x1))) || (!y1 && (y2 || x2 - x1))){
				if (x1) x1--;
				t++;
				continue;
			}
			if (y1) y1--;
			t++;
		}
		else{
			if ((y2 == 0 || y2 - 1 == 0) && (x2 == 0 || x2-1 == 0)){
				y2 = 0;
				x2 = 0;
				break;
			}
			if ((x2-1 != x1 && x2) || (y2-1 != y1 && y2)){
				if (x2 > 0) x2--;
				if (y2 > 0) y2--;
				t++;
				continue;
			}
			if (y2 && (y2-1 != y1 || x1 != x2)){
				if (y2) y2--;
				t++;
				continue;
			}
			if (x2 && (x2 -1 != x1 || y1 != y2)){
				//cout << "adfd";
				x2--;
			}
			t++;
		}
	}
	if (!x1 && !y1){
		cout << "Polycarp";
		return 0;
	}
	else {
		cout <<"Vasiliy";
	}
}