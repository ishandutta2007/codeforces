#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string s;

int main(){
	cin >> s;
	int last = -1;
	int mx = -1;
	for(int i = 0;i<s.size();i++){
		if(s[i] == 'A' || s[i] == 'E' || s[i] == 'U' || s[i] == 'I' || s[i] == 'O' || s[i] == 'Y'){
			mx = max(i-last,mx);
			last = i;
		}
	}
	mx = max(mx,int(s.size())-last);
	printf("%d\n",mx);
}