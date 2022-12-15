#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int dimGrille;
	cin >> dimGrille;
	vector<vector<int>> grille(dimGrille, vector<int>(dimGrille));

	auto repRequete = [&](int iLig, int iCol)
	{
		cout << grille[iLig][iCol] << ' ' << iLig+1 << ' ' << iCol+1 << endl;
	};
	
	int colPar[2];
	for (int par(0); par < 2; ++par)
	{
		int colInterdite;
		cin >> colInterdite;
		for (int potPol(1); potPol <= 3; ++potPol)
			if (potPol != colInterdite and potPol != colPar[!par])
			{
				colPar[par] = potPol;
				break;
			}
		grille[0][par] = colPar[par];
		repRequete(0, par);
	}

	vector<pair<int, int>> posPar[2];
	for (int lig(0); lig < dimGrille; ++lig)
		for (int col(0); col < dimGrille; ++col)
			if (lig or lig + col != (lig + col)%2)
				posPar[(lig+col)%2].emplace_back(lig, col);
	int autreCouleur(1);
	while (autreCouleur == colPar[0] or autreCouleur == colPar[1])
		autreCouleur++;

	for (int iRequete(2); iRequete < dimGrille * dimGrille; ++iRequete)
	{
		int colInterdite;
		cin >> colInterdite;
		if (colInterdite != colPar[0])
		{
			if (!posPar[0].empty())
			{
				auto [lig, col] = posPar[0].back();
				posPar[0].pop_back();
				grille[lig][col] = colPar[0];
				repRequete(lig, col);
			}
			else
			{
				auto [lig, col] = posPar[1].back();
				posPar[1].pop_back();
				grille[lig][col] = colInterdite == colPar[1] ? autreCouleur : colPar[1];
				repRequete(lig, col);
			}
		}
		else // == colPar[0]
		{
			if (!posPar[1].empty())
			{
				auto [lig, col] = posPar[1].back(); posPar[1].pop_back();
				grille[lig][col] = colPar[1];
				repRequete(lig, col);
			}
			else
			{
				auto [lig, col] = posPar[0].back();
				posPar[0].pop_back();
				grille[lig][col] = autreCouleur;
				repRequete(lig, col);
			}
		}
	}
}