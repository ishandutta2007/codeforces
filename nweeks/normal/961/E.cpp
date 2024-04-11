#include <bits/stdc++.h>
using namespace std;

struct Element
{
	int val, ind;

	bool operator<(Element other) const
	{
		return val < other.val;
	}
};

class Fenwick
{
	public:
		Fenwick(int n)
		{
			N = n;
			elem.resize(n+1);
			fill(elem.begin(), elem.end(), 0);
			for (int i(0); i < n; ++i)
				update(1, i);
		}

		void update(int x, int ind)
		{
			ind++;
			while (ind <= N)
			{
				elem[ind] += x;
				ind += ind & (-ind);
			}
		}

		int getsum(int ind)
		{
			ind++;
			int ans(0);
			while (ind > 0)
			{
				ans += elem[ind];
				ind -= ind & (-ind);
			}
			return ans;
		}

	private:
		int N;
		vector<int> elem;
};

const int MAXN = 2e5;

Fenwick fen = Fenwick(MAXN+1);
Element elements[MAXN];
bool visited[MAXN];
int arr[MAXN];

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	fen = Fenwick(N+1);
	priority_queue<Element> Q;
	for (int i(0); i < N; ++i)
	{
		cin >> elements[i].val;
		elements[i].ind = i;
		elements[i].val--;
		elements[i].val = min(elements[i].val, N-1);
		arr[i] = elements[i].val;
		Q.push({-elements[i].val, i});
	}
	//sort(elements, elements + N);
	long long ans(0);
	for (int i(0); i < N; ++i)
	{
		while (!Q.empty() and -Q.top().val < i)
		{
			int c = Q.top().ind; Q.pop();
			if (!visited[c])
			{
				fen.update(-1, c);
				visited[c] = true;
			}
		}
		if (!visited[i])
			fen.update(-1, i);
		visited[i] = true;
		if (arr[i] >= i)
			ans += fen.getsum(arr[i]) - (i ? fen.getsum(i-1) : 0);
	}
	cout << ans << endl;
}