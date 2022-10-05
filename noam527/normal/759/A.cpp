#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int p[200005], r[200005], n, v, sum = 0, b;

void ShowParents()
{
	for (int i = 0; i < n; i++) cout << i << ": " << p[i] << endl;
}

void MakeSet(int a)
{
	p[a] = a;
	r[a] = 0;
}

int FindSet(int a)
{
	if (a != a[p])
		a[p] = FindSet(a[p]);
	return a[p];
}

void Union(int a, int b)
{
	if (a != b)
	{
		if (r[a] > r[b])
			p[b] = a;
		else
		{
			p[a] = b;
			if (r[a] == r[b])
				r[b]++;
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) MakeSet(i);
	//ShowParents();
	for (int i = 0; i < n; i++)
	{
		cin >> v;
		//cout << "uniting " << i << " and " << v - 1 << endl;
		Union(FindSet(i), FindSet(v - 1));
		//ShowParents();
	}
	for (int i = 0; i < n; i++)
	{
		cin >> b;
		sum += b;
	}
	unordered_set<int> differents;
	for (int i = 0; i < n; i++)
		differents.insert(FindSet(i));
	if (differents.size() == 1) cout << 1 - sum % 2 << endl;
	else cout << differents.size() + (1 - sum % 2) << endl;
	return 0;
}