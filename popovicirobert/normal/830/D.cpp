#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))
#define uint unsigned int
    
using namespace std;

const int MOD = (int) 1e9 + 7;
const int MAXK = 405;

int dp[MAXK][2 * MAXK];

inline void mod(int &x) 
{
	if(x >= MOD) x -= MOD;
}

inline void add(int &x, int y) 
{
	x += y;
	mod(x);
}
   
int main() 
{
#if 0
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
   	int i, k;
    ios::sync_with_stdio(false);
   	cin.tie(0), cout.tie(0);

	cin >> k;

	// dp[i][j] = ai i lvl-uri si j drumuri disjuncte
	
	dp[1][0] = dp[1][1] = 1;
	for(i = 2; i <= k; i++) 
	{
		for(int a = 0; a <= k; a++) 
		{
			if(dp[i - 1][a] == 0) continue; 

			for(int b = 0; b <= k; b++) 
			{
				if(dp[i - 1][b] == 0) continue;

				int x = (1LL * dp[i - 1][a] * dp[i - 1][b]) % MOD;

				//add(dp[i][a + b], x); // nu treci deloc prin root
				add(dp[i][a + b], (2LL * x * (a + b) + x) % MOD); // adaugi root la un drum din stanga, la inceput sau la sfarsit
													              // adaugi root la un drum din dreapta, la inceput sau la sfarsit

				add(dp[i][a + b + 1], x); // faci root un nou drum
				if(a + b > 0) 
				{
					int two = (a + b) * (a + b - 1);
					add(dp[i][a + b - 1], (1LL * two * x) % MOD); // iei doua drumuri si le combini, trecandu-le prin root
				}
			}

		}
	}

	cout << dp[k][1];

	return 0;
}