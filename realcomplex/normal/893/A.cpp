#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int v[2];
	v[0] = 1,v[1] = 2;
	int k;
	for(int i = 0;i<n;i++){
		cin >> k;
		if(k==v[0]){
			if(v[0]==1&&v[1]==2)
				v[1] = 3;
			else if(v[0]==2&&v[1]==3)
				v[1] = 1;
			else		
				v[1] = 2;
		}
		else if(k==v[1]){
			if(v[0] == 1 && v[1] == 2)
				v[0] = 3;
			else if(v[0] == 2 && v[1] == 3)
				v[0] = 1;
			else
				v[0] = 2;
		}
		else{
			cout << "NO\n";
			exit(0);
		}
		sort(v,v+2);
	}
	cout << "YES\n";
	return 0;	
}