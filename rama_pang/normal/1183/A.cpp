#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define db(x) cout << ">>>>>>>>>>>>>" << #x << " "<< x << endl
#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int sum(int n){
	int total=0;
	int save=n;
	for (int i = 0; i <=log10(save); i++){
		total+= n%10;
		n=n/10;
		
	}
	return total;
}
int main (){
	int n;
	cin >> n;
	while (sum(n)%4!=0){
		//cout << sum(n)<<endl;
		n++;
	}
	cout << n << endl;
}