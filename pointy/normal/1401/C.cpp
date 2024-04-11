#include<bits/stdc++.h>
using namespace std;
int a[100001],b[100001]; 
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i=1;i<=n;i++) 
		{
			cin >> a[i];
			b[i]=a[i];
		}
		sort(b+1,b+n+1);
		for (int i=1;i<=n;i++) 
		{
			if (a[i]!=b[i]&&a[i]%b[1]!=0)
			{
				cout << "NO" << endl;
				goto no;
			}
		}
		cout << "YES" << endl;
		no:;
	}
    return 0;
}