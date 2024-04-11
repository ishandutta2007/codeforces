#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;


vector<ll> mul(100001);
int pos = 0;
ll ans = 0;
int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		string type;
		cin >> type;
		mul[0] = 1;
		if(type == "add"){
			if(mul[pos] == -1){
				cout << "OVERFLOW!!!";
				return 0;
			}
			ans += mul[pos];
			if(ans > (1LL << 32) - 1){
				cout << "OVERFLOW!!!";
				return 0;
			}
		}else if(type == "for"){
			int k;
			cin >> k;
			pos++;
			if(mul[pos-1] == -1){
				mul[pos] = -1;
			}else{
				mul[pos] = mul[pos-1] * k;
				if(mul[pos] > (1LL << 32) - 1){
					mul[pos] = -1;
				}
			}
		}else if(type == "end"){
			pos--;
		}
	}
	cout << ans;
}