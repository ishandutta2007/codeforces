#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;

int main(){
//	IOS;
	long long int inp;
	cin >> inp;
	if(inp&1 && inp>=5){
		cout << "1 " << (inp-3)/2 << endl;
	}
	else cout << "NO\n";
	return 0;
}