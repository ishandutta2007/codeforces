#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N;
	int ud = 0;
	int lr = 0;
	cin >> N;
	string s;
	for(int i=0;i<N;i++)
	{
		cin >> s;
		if(s.size()==4)
			ud++,lr++;
		else if((s=="UR")||(s=="DL"))
			ud++;
		else
			lr++;
	}
	long long ans = ((long long)(++ud))*((long long)(++lr));
	cout << ans << endl;
	return 0;
}