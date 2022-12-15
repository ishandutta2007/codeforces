#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 2e5+1;
const int MAXP = 18;
const int NB_FEUILLES = 1 << 18;

int perm[MAXN], arr[MAXN], last[MAXN], nxt[MAXP][MAXN], invPerm[MAXN];
int seg[2 * NB_FEUILLES];
int finPerm[MAXN];


signed main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int lenPerm, lenArr, nbRequetes;
	cin >> lenPerm >> lenArr >> nbRequetes;
	for (int iPerm = 0; iPerm < lenPerm; ++iPerm) 
	{
		cin >> perm[iPerm];
		--perm[iPerm];
		invPerm[perm[iPerm]] = iPerm;
	}
	for (int iArr = 0; iArr < lenArr; ++iArr) 
	{
		cin >> arr[iArr];
		--arr[iArr];
	}
	
	for (int iPerm = 0; iPerm < lenPerm; ++iPerm) 
		last[iPerm] = lenArr;
	nxt[0][lenArr] = lenArr;
	for (int iArr(lenArr-1); iArr >= 0; --iArr)
	{
		int voulu = perm[ (1 + invPerm[arr[iArr]]) % lenPerm];
		nxt[0][iArr] = last[voulu];
		last[arr[iArr]] = iArr;
	}

	for (int p = 0; p < MAXP-1; ++p) 
		for (int iArr = 0; iArr <= lenArr; ++iArr) 
			nxt[p+1][iArr] = nxt[p][nxt[p][iArr]];

	for (int iPos(0); iPos < MAXN; ++iPos)
	{
		finPerm[iPos] = iPos;
		for (int p = 0; p < MAXP; ++p) 
			if ((1 << p) & (lenPerm-1))
				finPerm[iPos] = nxt[p][finPerm[iPos]];
	}

	for (int i = 0; i < 2 * NB_FEUILLES; ++i) 
		seg[i] = lenArr;
	for (int i(0); i < lenArr; ++i)
		seg[i + NB_FEUILLES] = finPerm[i];
	for (int i(NB_FEUILLES-1); i; --i)
		seg[i] = min(seg[2*i], seg[2*i+1]);

	for (int iRequetes = 0; iRequetes < nbRequetes; ++iRequetes) 
	{
		int deb, fin;
		cin >> deb >> fin;
		int maxPossible = fin-1;
		--deb, --fin;
		deb += NB_FEUILLES, fin += NB_FEUILLES;
		int sol = lenArr;
		while (deb < fin)
		{
			/*
			 * 1
			 * 2 3
			 * 4 5 6 7
			 */
			if (deb % 2)
				sol = min(sol, seg[deb++]);
			if (fin % 2 == 0)
				sol = min(sol, seg[fin--]);
			fin /= 2, deb /= 2;
		}
		if (deb == fin)
			sol = min(sol, seg[deb]);
		cout << (sol <= maxPossible ? '1' : '0');
	}
	cout << endl;
}