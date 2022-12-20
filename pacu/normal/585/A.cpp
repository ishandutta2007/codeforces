#include <iostream>
#include <vector>
using namespace std;

long long v[4000];
long long d[4000];
long long p[4000];
bool inq[4000];
int N;
vector<int> treat;

int main()
{
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> v[i] >> d[i] >> p[i];
		inq[i] = 1;
	}	
	int ans = 0;
	for(int i=0;i<N;i++)
	{
		if(!inq[i]) continue;
		inq[i] = 0;
		ans++;
		treat.push_back(i);
		long long dec = v[i];
		long long dec2 = 0;
		for(int j=i+1;j<N;j++)
		{
			if(inq[j])
			{
				p[j] -= dec;
				p[j] -= dec2;
				if(p[j] < 0)
				{
					inq[j] = 0;
					dec2 += d[j];
				}
				if(dec > 0) dec--;
			}
		}
	}
	cout << ans << '\n';
	for(int i=0;i<ans;i++)
		cout << treat[i]+1 << ' ';
	cout << '\n';
}