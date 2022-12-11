#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin >> s;
	int cnt1 = 0,cnt2 = 0,cnt3 = 0,cnt4 = 0,cnt5 = 0;
	for(int j = 0;j<s.size();j++)
		for(int i = 1;i<=s.size()-j;i++){
			if(s.substr(j,i)=="Danil")cnt1++;
			else if(s.substr(j,i)=="Olya")cnt2++;
			else if(s.substr(j,i)=="Slava")cnt3++;
			else if(s.substr(j,i)=="Ann")cnt4++;
			else if(s.substr(j,i)=="Nikita")cnt5++;
		}
	if(cnt1+cnt2+cnt3+cnt4+cnt5==1)cout << "YES";
	else cout << "NO";
	return 0;
}