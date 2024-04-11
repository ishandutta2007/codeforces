#include "bits/stdc++.h"
using namespace std;
int a , ta;
int b , tb;
int hh , mm;
char tmp;
int ans = 0;
int main(){
	cin >> a >> ta;
	cin >> b >> tb;
	cin >> hh >> tmp >> mm;
	int start = hh * 60 + mm - tb + 1;
	int finish = hh * 60 + mm + ta - 1;
	for(int i = 5 * 60 ; i <= 23 * 60 + 59 ; i += b){
		if(i >= start && i <= finish){
			++ans;
		}
	}
	cout << ans;
}