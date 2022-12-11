#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin >> s;
	int cntx = 0,cnty = 0;
	for(char x : s){
		if(x=='y')cnty++;
		else cntx++;
	}
	if(cntx>cnty)
		for(int i = 0;i<cntx-cnty;i++)
			cout << "x";
	else
		for(int j = 0;j<cnty-cntx;j++)
			cout << "y";
	return 0;
}