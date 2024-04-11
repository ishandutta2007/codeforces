#include <iostream>
using namespace std;

int N,K,Q;
int t[150001];

int lst[6];

int main()
{
	cin >> N >> K >> Q;
	for(int i=0;i<N;i++)
		cin >> t[i];
	t[N] = -1;
	for(int i=0;i<6;i++)
		lst[i] = N;
	int tp,d;
	for(int i=0;i<Q;i++)
	{
		cin >> tp >> d;
		d--;
		if(tp==1)
		{
			for(int i=0;i<6;i++)
			{
				if(t[lst[i]] <= t[d])
				{
					for(int j=4;j>=i;j--)
						lst[j+1] = lst[j];
					lst[i] = d;
					break;
				}
			}
		}
		else
		{
			bool ok = 0;
			for(int j=0;j<K;j++)
				if(lst[j]==d)
					ok = 1;
			if(ok) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}