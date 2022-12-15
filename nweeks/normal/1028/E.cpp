#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

/*

Si on fixe le dernier element x?
On sait que celui d'avant doit etre de la forme kx + b[n-1]
celui d'avant doit etre de la forme 
A quelle condition sur le nombre suivant peut-on trouver un nombre qui convient ?
Il suffit que celui d'aprs soit plus grand !!
Mais probleme quand on choisit a[1]...
il faut que x ait la bonne congruence modulo a[1]. 

ON PART DU MAX !!
Si le max est pas atteint deux fois consecutivement c'est ez ?
Si le max est atteint deux fois consecutivement ?
  i i+1	
  x x
a[i] congru a x mod a[i+1] 
a[i+1] = x + ka[i+2]
a[i] = x + lx + lka[i+2]

*/

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int nb_elem;
	cin >> nb_elem;
	vector<ll> arr(nb_elem);
	for (auto &v : arr)
		cin >> v;
	bool all_same(true);
	for (int i(1); i < nb_elem; ++i)
		if (arr[i] != arr[0])
			all_same = false;
	if (all_same)
	{
		if (arr[0])
			cout << "NO" << endl;
		else
		{
			cout << "YES" << endl;
			for (int i(0); i < nb_elem; ++i)
				cout << 1 << ' ';
			cout << endl;
		}
		return 0;
	}
	ll biggest_elem = *max_element(arr.begin(), arr.end());
	int start;
	for (int i(0); i < nb_elem; ++i)
		if (arr[(i+1)%nb_elem] == biggest_elem and arr[i] != biggest_elem)
			start = i;
	vector<ll> sol(nb_elem);
	sol[(start+1)%nb_elem] = biggest_elem;
	for (int i(start); i != (start+1)%nb_elem; i = (i-1+nb_elem)%nb_elem)
	{
		sol[i] = sol[(i+1)%nb_elem] + arr[i];
		if (sol[i] <= biggest_elem)
			sol[i] += sol[(i+1)%nb_elem];
	}
	cout << "YES" << endl;
	for (int i(0); i < nb_elem; ++i)
		cout << sol[i] <<' ';
	cout << endl;
}