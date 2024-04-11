#include <iostream>
#include <string>
using namespace std;

int main()
{
	string N;
	cin >> N;
	int ans = 0;
	for(int i=0;i<N.size();i++)
		ans = (ans*2)+(N[i]-'0')/3;
	cout << ans << endl;
	return 0;
}