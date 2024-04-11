#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int n, m, p[200005], a[200005], b[200005], c[200005];

void Show(set<int> a)
{
	for (set<int>::iterator i = a.begin(); i != a.end(); i++) cout << *i << " ";
	cout << endl;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> p[i];
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	cin >> m;
	for (int i = 0; i < m; i++) cin >> c[i];
	set<int> col1, col2, col3;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 1 || b[i] == 1)
			col1.insert(p[i]);
		if (a[i] == 2 || b[i] == 2)
			col2.insert(p[i]);
		if (a[i] == 3 || b[i] == 3)
			col3.insert(p[i]);
	}
	//Show(col1);
	//Show(col2);
	//Show(col3);
	int price;
	for (int i = 0; i < m; i++)
	{
		if (c[i] == 1)
		{
			if (col1.size() == 0)
			{
				cout << -1 << endl;
				continue;
			}
			price = *col1.begin();
			col1.erase(col1.begin());
			col2.erase(price);
			col3.erase(price);
		}
		else if (c[i] == 2)
		{
			if (col2.size() == 0)
			{
				cout << -1 << endl;
				continue;
			}
			price = *col2.begin();
			col2.erase(col2.begin());
			col1.erase(price);
			col3.erase(price);
		}
		else
		{
			if (col3.size() == 0)
			{
				cout << -1 << endl;
				continue;
			}
			price = *col3.begin();
			col3.erase(col3.begin());
			col2.erase(price);
			col1.erase(price);
		}
		//Show(col1);
		//Show(col2);
		//Show(col3);
		cout << price << " ";
	}
}