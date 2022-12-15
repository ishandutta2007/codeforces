#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int nbRequetes;
	cin >> nbRequetes;
	priority_queue<pair<int, int>> pq;
	set<int> served;
	queue<int> q;
	int nbVus(0);
	while (nbRequetes--)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			nbVus++;
			int m;
			cin >> m;
			pq.push({m, -nbVus});
			q.push(nbVus);
		}
		else if (t == 2)
		{
			while (served.count(q.front()))
				q.pop();
			cout << q.front() << ' ';
			served.insert(q.front());
			q.pop();
		}
		else
		{
			while (served.count(-pq.top().second))
				pq.pop();
			cout << -pq.top().second << ' ';
			served.insert(-pq.top().second);
			pq.pop();
		}
	}
	cout << endl;
}