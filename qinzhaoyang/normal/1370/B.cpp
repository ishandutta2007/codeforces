#include <iostream>

using namespace std;

int n , a[2002];
int t1[2002] , cnt1;
int t2[2002] , cnt2;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		cnt1 = cnt2 = 0;
		cin >> n;
		n *= 2;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			if(a[i] % 2 == 1)
				t1[++cnt1] = i;
			else
				t2[++cnt2] = i;
		}
		if(cnt1 % 2 == 1)
		{
			for(int i = 1; i < cnt1; i += 2)
				cout << t1[i] << " " << t1[i + 1] << endl;
			for(int i = 1; i < cnt2; i += 2)
				cout << t2[i] << " " << t2[i + 1] << endl;
		}
		else
		{
			if(cnt1 >= 2)
			{
				for(int i = 3; i <= cnt1; i += 2)
					cout << t1[i] << " " << t1[i + 1] << endl;
				for(int i = 1; i <= cnt2; i += 2)
					cout << t2[i] << " " << t2[i + 1] << endl;
			}
			else
			{
				for(int i = 1; i <= cnt1; i += 2)
					cout << t1[i] << " " << t1[i + 1] << endl;
				for(int i = 3; i <= cnt2; i += 2)
					cout << t2[i] << " " << t2[i + 1] << endl;
			}
		}
	}
	return 0;
}