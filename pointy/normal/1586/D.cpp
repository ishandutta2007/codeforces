#include <bits/stdc++.h>
using namespace std;
int n,p[105],ans,a[105]; 
bool check(int x)
{
	int u=n-x+1;
	cout << "? ";
	for (int i=1;i<n;i++) cout << "1 ";
	cout << u+1 << endl;
	fflush(stdout);
	int w;
	cin >> w;
	if (w==0) return 1;
	return 0;
}
void print()
{
	cout << "! ";
	for (int i=1;i<=n;i++) cout << p[i] <<" ";
	cout << endl;
	fflush(stdout);
}
int find(int x)
{
	if (x<ans)
	{
		int u=ans-x+1;
		cout << "? ";
		for (int i=1;i<n;i++) cout << u << " ";
		cout << 1 << endl;
		fflush(stdout);
		int w;
		cin >> w;
		return w;
	}
	else
	{
		int u=x-ans+1;
		cout << "? ";
		for (int i=1;i<n;i++) cout  << "1 ";
		cout << u << endl;
		fflush(stdout);
		int w;
		cin >> w;
		return w;
	}
}
int main()
{
    cin >> n;
    ans=1;
    for (int i=n;i>=2;i--)
    {
    	if (check(i)) 
    	{
    		ans=i;
    		break;
		}
	}
	a[ans]=n;
	for (int i=1;i<=n;i++)
	{
		if (i==ans) continue;
		a[i]=find(i);
	}
	for (int i=1;i<=n;i++) p[a[i]]=i;
	print();
    return 0;
}