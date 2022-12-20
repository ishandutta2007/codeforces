#include <iostream>
#include <vector>
#include <string>
using namespace std;

string A;
bool occ[26];
vector<string> st;

int main()
{
	int N;
	cin >> N >> A;
	if(N==1)
	{
		cout << "YES\n";
		cout << A << endl;
		return 0;
	}
	for(int i=0;i<26;i++)
		occ[i] = 0;
	int start = 0;
	occ[A[0]-'a'] = 1;
	for(int i=1;i<A.size();i++)
	{
		if(!occ[A[i]-'a'])
		{
			occ[A[i]-'a'] = 1;
			st.push_back(A.substr(start,i-start));
			start = i;
		}
		if(st.size() == N-1)
			break;
	}
	st.push_back(A.substr(start,A.size()-start));
	if(st.size() < N)
		cout << "NO\n";
	else
	{
		cout << "YES\n";
		for(int i=0;i<N;i++)
			cout << st[i] << endl;
	}
	return 0;
}