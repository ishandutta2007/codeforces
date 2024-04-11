#include <iostream>
#include <string.h>

#define N 1000010

using namespace std;

char str[N];
int arr[N];

int main() {
	int i,a,b,l;
	cin >> str;
	a = 1;
	b = l = strlen(str);
	for(i=0;str[i];i++) {
		if(str[i] == 'l')
			arr[b--] = i+1;
		else
			arr[a++] = i+1;
	}
	for(i=1;i<=l;i++)
		cout << arr[i] << endl;
	return 0;
}