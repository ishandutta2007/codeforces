#include <iostream>
#include <string.h>

#define N 110

using namespace std;

char str[N];

int main() {
	int i,cnt;
	bool check = false;
	cin >> str;
	int l = strlen(str);
	for(i=cnt=1;i<l;i++) {
		if(str[i] != str[i-1])
			cnt = 1;
		else
			cnt++;
		if(cnt >= 7)
			check = true;
	}
	if(check)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}