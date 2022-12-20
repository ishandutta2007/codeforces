#include <iostream>
#include <vector>
using namespace std;

int A[150000];
int N;
int B[150000];

vector<int> bad;

bool okay(int i)
{
	if(i<0) return 1;
	if(i>=N-1) return 1;
	if(i%2==0) return A[i]<A[i+1];
	else return A[i]>A[i+1];
}

int main()
{
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> A[i];
	for(int i=0;i<N;i++)
	{
		if((i>0 && !okay(i-1))||(i<N-1 && !okay(i)))
			bad.push_back(i);
	}
	if(bad.size()>6)
	{
		cout << 0 << '\n';
		return 0;
	}
	int ans = 0;
	for(int i=0;i<bad.size();i++)
	{
		for(int j=i+1;j<bad.size();j++)
		{
			for(int k=0;k<N;k++)
				B[k] = A[k];
			swap(A[bad[i]],A[bad[j]]);
			bool good = 1;
			for(int i=0;i<N-1;i++)
				good = (good && okay(i));
			ans += good;
			for(int k=0;k<N;k++)
				A[k] = B[k];
		}
	}
	if(bad.size() <= 3)
	{
		if(bad.size()==2)
		{
			for(int i=0;i<2;i++)
			{
				for(int j=0;j<N;j++)
				{
					if(j!=bad[i]-1 && j!=bad[i] && j!=bad[i]+1)
					{
						swap(A[bad[i]],A[j]);
						if(okay(bad[i]-1) && okay(bad[i]) && okay(j-1) && okay(j))
						{
							ans++;
						}
						swap(A[bad[i]],A[j]);
					}
				}
			}
		}
		else
		{
			for(int i=1;i<=1;i++)
			{
				for(int j=0;j<N;j++)
				{
					if(j!=bad[i]-1 && j!=bad[i] && j!=bad[i]+1)
					{
						swap(A[bad[i]],A[j]);
						if(okay(bad[i]-1) && okay(bad[i]) && okay(j-1) && okay(j))
						{
							ans++;
						}
						swap(A[bad[i]],A[j]);
					}
				}
			}			
		}
	}
	cout << ans << '\n';
}