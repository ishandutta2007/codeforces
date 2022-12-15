#include <bits/stdc++.h>
using namespace std;

struct Segment_tree
{
public:
	Segment_tree(const vector<int> elem)
	{
		N = elem.size();
		int H = ceil(log2(N)) + 1;
		seg.resize(1<<H);
		fill(seg.begin(), seg.end(), 0);

		init(0, 0, N-1, elem);
	}

	int get_val(void) const
	{
		return seg[0];
	}

	void print_tree(void)
	{
		cout << "------------------\n";
		int cur(0);
		for (int i(0); i <= ceil(log2(N))+1; ++i)
		{
			for (int k(0); k < (1<<i); ++k, ++cur)
				cout << seg[i] << ' ';
			cout << endl;
		}
	}

	int init(int node, int l, int r, const vector<int> &elem)
	{
		if (l == r)
		{
			seg[node] = elem[l];
			return 0;
		}
		int type = init(2*node+1, l, (l+r)/2, elem);
		init(2*node+2, (l+r)/2+1, r, elem);
		if (!type)
			seg[node] = seg[2*node+1]|seg[2*node+2];
		else
			seg[node] = seg[2*node+1]^seg[2*node+2];
		return type^1;
	}

	int update(int node, int l, int r, int ind, int val)
	{
		if (l > ind or r < ind)
			return -1;
		if (l == r)
		{
			seg[node] = val;
			return 0;
		}
		int q1 = update(2*node+1, l, (l+r)/2, ind, val);
		int q2 = update(2*node+2, (l+r)/2+1, r, ind, val);
		if (!q1 or !q2)
		{
			seg[node] = seg[2*node+1]|seg[2*node+2];
			return 1;
		}
		seg[node] = seg[2*node+1]^seg[2*node+2];
		return 0;
	}
private:
	vector<int> seg;
	int N;
};

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int N, M;
	cin >> N >> M;
	N = 1<<N;
	vector<int> elem(N);
	for (auto &v : elem) cin >> v;
	Segment_tree seg = Segment_tree(elem);

	while (M--)
	{
		//seg.print_tree();
		int p, b;
		cin >> p >> b;
		seg.update(0, 0, N-1, p-1, b);
		cout << seg.get_val() << '\n';
	}
}