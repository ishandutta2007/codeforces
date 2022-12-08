#include <iostream>
using namespace std;
int Q;
int main(){
	ios_base::sync_with_stdio(false);
	cin >> Q;
	for(int i=1, k, ans;i<=Q;++i){
		cin >> k;
		if(k%4==0){
			ans=k/4;
			cout << ans << endl;
			continue;
		}
		if(k%4==1){
			if(k<9)	cout << "-1" << endl;
			else{
				ans=(k-9)/4+1;
				cout << ans << endl;
			}
			continue;
		}
		if(k%4==2){
			if(k<6)	cout << "-1" << endl;
			else{
				ans=(k-2)/4;
				cout << ans << endl;
			}
			continue;
		}
		if(k%4==3){
			if(k<15)	cout << "-1" << endl;
			else{
				ans=(k-15)/4+2;
				cout << ans << endl;
			}
			continue;
		}
	}
	return 0;
}