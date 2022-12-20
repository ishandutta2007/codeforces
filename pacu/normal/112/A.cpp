#include <iostream>
#include <string>
#include <vector>
using namespace std;
int isUpper(char c)
{
	return c<=90;
}
char toLower(char c)
{
	return c+32;
}

int check()
{
	string a,b;
	cin >> a;
	cin >> b;
	char ca,cb;
	for(int i=0;i<a.size();i++)
	{
		ca = a[i];
		cb = b[i];
		if(isUpper(ca)) ca = toLower(ca);
		if(isUpper(cb)) cb = toLower(cb);
		if(ca<cb) return -1;
		if(ca>cb) return 1;
	}
	return 0;
}
int main()
{
	cout << check() << endl;
}