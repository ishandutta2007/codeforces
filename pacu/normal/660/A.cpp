#include <iostream>
#include <vector>
using namespace std;

int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}

int main()
{
	int N;
	int prev,a;
	prev = 1;
	vector<int> ans;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> a;
		if(gcd(prev,a)>1) ans.push_back(1);
		ans.push_back(a);
		prev = a;
	}
	cout << ans.size()-N << '\n';
	for(int i=0;i<ans.size();i++)
		cout << ans[i] << ' ';
	cout << '\n';
}