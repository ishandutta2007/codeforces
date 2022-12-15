#include <bits/stdc++.h>

using namespace std;

class Fenwick
{
	public:
		Fenwick(int taille)
		{
			N = taille;
			elem.resize(N+1);
			for (int i(1); i <= N; ++i)
				elem[i] = 0;
			tot =0;
		}

		void update(int x, int ind)
		{
			++ind;
			tot += x;
			while (ind <= N)
			{
				elem[ind] += x;
				ind += ind & (-ind);
			}
		}

		int summ(int ind)
		{
			int ans = 0;
			++ind;
			while (ind > 0)
			{
				ans += elem[ind];
				ind -= ind & (-ind);
			}
			return ans;
		}

		int total(void)
		{
			return tot;
		}

	private:
		int N;
		vector<int> elem;
		int tot;
};

const int MOD = 2;
const int MAX = 2e5;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;

	vector<int> nombres(N), pos(N);
	for (int i(0); i < N; ++i)
		pos[i] = i;
	for (auto& v : nombres) 
	{
		cin >> v;
		--v;
	}

	Fenwick after = Fenwick(N);

	int ans(0);

	for (int i(0); i < N; ++i)
	{
		ans += after.total() - after.summ(pos[nombres[i]]);
		ans %= MOD;
		after.update(1, pos[nombres[i]]);
	}
	
	if (ans == (N%2))
		cout << "Petr" << endl;
	else
		cout << "Um_nik" << endl;
}