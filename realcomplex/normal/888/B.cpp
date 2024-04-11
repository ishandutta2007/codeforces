#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	char s;
	int up = 0,down = 0,left = 0,right = 0;
	for(int j = 0;j<n;j++){
		cin >> s;
		if(s=='U')up++;
		else if(s=='D')down++;	
		else if(s=='L')left++;
		else right++;
	}
	cout << min(up,down)*2+min(left,right)*2 << "\n";
	return 0;
}