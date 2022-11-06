#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 1E6;
int a[MAXN + 1];
vector<int> adjList[MAXN + 1];
vector<tuple<int, int, int>> queries[MAXN + 1];
int ans[MAXN];
int freq[MAXN + 1];
int lb[MAXN + 1];
int seq[MAXN + 1];
int invseq[MAXN + 1];

void seq_swap(int pos1, int pos2)
{
	swap(seq[pos1], seq[pos2]);
	swap(invseq[seq[pos1]], invseq[seq[pos2]]);
}

void solve(int v, int p, int n)
{
	//cout << "at " << v << endl;
	//cout << "\tseq ";
	//for (int i = 1; i <= n; i++)
	//{
		//cout << seq[i] << " \n"[i == n];
	//}
	//cout << "\tinvseq ";
	//for (int i = 1; i <= n; i++)
	//{
		//cout << invseq[i] << " \n"[i == n];
	//}
	//cout << "\tlb ";
	//for (int i = 1; i <= n; i++)
	//{
		//cout << lb[i] << " \n"[i == n];
	//}
	seq_swap(invseq[a[v]], lb[freq[a[v]] + 1] - 1);
	freq[a[v]]++;
	lb[freq[a[v]]]--;
	for (tuple<int, int, int> tup : queries[v])
	{
		int l = get<0>(tup);
		int k = get<1>(tup);
		int ans_ind = get<2>(tup);
		int ind = lb[l];
		if (k + ind - 1 > n)
			ans[ans_ind] = -1;
		else
			ans[ans_ind] = seq[k + ind - 1];
	}
	for (int adj : adjList[v])
	{
		if (adj == p)
			continue;
		solve(adj, v, n);
	}
	seq_swap(invseq[a[v]], lb[freq[a[v]]]);
	lb[freq[a[v]]]++;
	freq[a[v]]--;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n, q;
		cin >> n >> q;
		fill(freq + 1, freq + n + 1, 0);
		for (int i = 0; i <= n; i++)
		{
			adjList[i].clear();
			queries[i].clear();
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		for (int i = 2; i <= n; i++)
		{
			int x;
			cin >> x;
			adjList[x].push_back(i);
			adjList[i].push_back(x);
		}
		for (int i = 0; i < q; i++)
		{
			int v, l, k;
			cin >> v >> l >> k;
			queries[v].push_back({l, k, i});
		}
		lb[0] = 1;
		for (int i = 1; i <= n; i++)
		{
			seq[i] = i;
			invseq[i] = i;
			lb[i] = n + 1;
		}
		solve(1, 1, n);
		for (int i = 0; i < q; i++)
			cout << ans[i] << " \n"[i == q - 1];
	}
	return 0;
}