#include <bits/stdc++.h>
#define SZ(v) ((int)(v).size())
using namespace std;
typedef long long ll; 

int nbChaines, nbVoulus;
vector<int> chaines;

struct Situation
{
	ll profondeur, restant;

	bool operator<(Situation other) const
	{
		if (profondeur == other.profondeur) return restant < other.restant;
		return profondeur > other.profondeur;
	}
};

bool can(ll maxProf)
{
	priority_queue<Situation> q;
	q.push(Situation{0, 0});
	ll curSeen(1);
	int id(0);
	while (!q.empty() and curSeen < nbVoulus and id < nbChaines)
	{
		auto [prof, restant] = q.top(); q.pop();
		if (restant and prof < maxProf) q.push(Situation{prof+1, restant-1});
		curSeen--;
		ll lft = (chaines[id]-1) / 2;
		ll rgt = chaines[id]-1 - lft;
		++id;
		if (prof+1 < maxProf)
		{
			assert(lft and rgt);
			q.push(Situation{prof+2, lft-1});
			q.push(Situation{prof+2, rgt-1});
			curSeen += min(maxProf, prof+1 + lft) - (prof + 1);;
			curSeen += min(maxProf, prof+1 +rgt) - (prof + 1);
		}
	}
	return curSeen >= nbVoulus;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> nbChaines >> nbVoulus;
	chaines.resize(nbChaines);
	for (auto &v : chaines) cin >> v;
	sort(chaines.rbegin(), chaines.rend());
	int cur(1);
	for (int i(0); i < nbChaines and cur < nbVoulus; ++i)
		cur += chaines[i] - 2;
	if (cur < nbVoulus)
	{
		cout << -1 << endl;
		return 0;
	}
	ll lo(1), up(1e18);
	while (lo < up)
	{
		ll mid = (lo + up)/2;
		if (can(mid)) up = mid;
		else lo = mid+1;
	}
	cout << lo << endl;
}