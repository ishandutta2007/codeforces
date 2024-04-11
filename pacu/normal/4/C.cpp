#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	map<string,int> m;
	int N;
	string s;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> s;
		m[s]++;
		if(m[s]==1)
			cout << "OK" << endl;
		else
			cout << s << m[s]-1 << endl;
	}
}