#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
	int oleg,g1,g2;
	cin >> oleg >> g1 >> g2;
	vector<int>poz;
	int sk;
	cin >> sk;
	int ska;
	for(int i = 0;i<sk;i++){
		cin >> ska;
		poz.push_back(ska);
	}
	sort(poz.begin(),poz.end());
	int skaits = 0;
	for(int i = 0;i<poz.size();i++){
		if(poz[i] > g1 && poz[i] < g2){
			skaits++;
		}
	}
	cout << skaits;
 
	return 0;
}