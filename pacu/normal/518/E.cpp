#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

long long A[100000];
int N,K;
bool question[100000];

struct bound
{
	vector<int> id;
	long long low,high;
};

bound B[200000];

int main()
{
	cin >> N >> K;
	string s;
	stringstream ss;
	for(int i=0;i<N;i++)
	{
		cin >> s;
		if(s[0]=='?')
			question[i] = 1;
		else
		{
			question[i] = 0;
			ss << s;
			ss >> A[i];
			ss.clear();
		}
	}

	for(int i=0;i<K;i++)
	{
		int last = i+N;
		B[last].low = -1500000001;
		B[last].high = 1500000001;
		for(int j=i;j<N;j+=K)
		{
			if(!question[j])
			{
				B[last].high = A[j]-1;
				B[j].low = A[j]+1;
				B[j].high = 1500000001;
				last = j;
			}
			else
				B[last].id.push_back(j);
		}
	}
	long long nm;
	for(int i=0;i<N+K;i++)
	{
		nm = B[i].id.size();
		if(nm==0) continue;
		if((B[i].high+1-B[i].low)<nm)
		{
			cout << "Incorrect sequence" << endl;
			return 0;
		}
		long long cur = -(nm/2);
		cur = max(cur,B[i].low);
		cur = min(cur,B[i].high+1-nm);
		for(int j=0;j<nm;j++)
			A[B[i].id[j]] = cur++;
	}
	for(int i=K;i<N;i++)
		if(A[i-K] >= A[i])
		{
			cout << "Incorrect sequence" << endl;
			return 0;
		}
	for(int i=0;i<N;i++)
		cout << A[i] << " ";
	cout << endl;
	return 0;
}