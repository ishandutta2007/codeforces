#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

#define P pair<int, int>

P arr[30];
int cnt[300];

int main(){
	/*
	cout << "Amin" << endl;
	/*/
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	for(int i = 0; i < s1.length(); i++)
		cnt[s1[i]]++;
	for(int i = 0; i < s2.length(); i++)
		cnt[s2[i]]--;
	string res = "YES";
	for(int i = 0; i < 300; i++)
		if(i != 32 && cnt[i] < 0)
			res = "NO";
	cout << res << endl;
	return 0;
	//*/
}