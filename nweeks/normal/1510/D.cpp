#include <bits/stdc++.h>
#define f long double
using namespace std;

const __int128 M = 1000 * 1000 * 1000;
const __int128 INFINI = M * M * M;
	
vector<int> entiers;
	
vector<vector<__int128>> dyn(100 * 1000 + 1, vector<__int128>(10, INFINI));

void affiche(vector<int> elems) {
	sort(elems.begin(), elems.end());
	cout << elems.size() << endl;

	for(int e : elems) {
		cout << e << " ";
	}
	cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	int nbEntiers, chiffre;
	cin >> nbEntiers >> chiffre;

	for(int iEntier = 0;iEntier < nbEntiers;iEntier++) {
		int entier;
		cin >> entier;

		if(chiffre % 2 != 0 && entier % 2 == 0)
			continue;
		if(chiffre % 5 != 0 && entier % 5 == 0)
			continue;
		entiers.push_back(entier);
	}
	nbEntiers = (int)entiers.size();

	dyn[0][1] = 1;
	for(int iEntier = 0;iEntier < nbEntiers;iEntier++) {
		for(int c = 0;c < 10;c++) {
			if(dyn[iEntier][c] >= INFINI) continue;

			dyn[iEntier + 1][c] = min(dyn[iEntier + 1][c], 
			dyn[iEntier][c] * entiers[iEntier]);
	
			dyn[iEntier + 1][(c * entiers[iEntier]) % 10] = min(
				dyn[iEntier + 1][(c * entiers[iEntier]) % 10],
				dyn[iEntier][c]
			);
		}
	}
	
	if(dyn[nbEntiers][chiffre] >= INFINI) {
		cout << -1 << endl;
		return 0;
	}
	
	vector<int> solution;
	
	int curChiffre = chiffre;
	for(int iEntier = nbEntiers - 1;iEntier >= 0;iEntier--) {
		for(int c = 0;c < 10;c++) {
			if((c * entiers[iEntier]) % 10 == curChiffre
			&& dyn[iEntier + 1][(c * entiers[iEntier]) % 10] == dyn[iEntier][c]) {
				curChiffre = c;
				solution.push_back(entiers[iEntier]);
				break;
			}
		}
	}
	
	if(solution.empty()) {
		cout << -1 << endl;
		return 0;
	}
	
	affiche(solution);
	return 0;
}