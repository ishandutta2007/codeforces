#include <iostream>
#include <string>
using namespace std;
int main()
{
	int N;
	string s;
	int count,i;
	cin >> N;
	cin >> s;
	for(i=1,count=0;i<N;i++)
		if(s[i]==s[i-1]) count++;
	cout << count << endl;
}