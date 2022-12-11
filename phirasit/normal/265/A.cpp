#include <iostream>
#include <string.h>

#define N 60

using namespace std;

char s[N],t[N];

int main() {
	int i,j;
	cin >> s >> t;
	for(i=j=0;t[j];j++) {
		if(s[i] == t[j])
			i++;
	}
	cout << i+1 << endl;
	return 0;
}