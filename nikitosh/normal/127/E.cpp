#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<cstring>
#include<string>
#include<cstdlib>
#include<ctime>
#include<cassert>

using namespace std;

#define FNAME ""
#define FILE 0

#define pb push_back
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define LD long double

#ifdef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

int n, a[2005][2005], d1[2005][4200], d2[2005][4200], l, r, ans, N;
char s[2005];

void update1 (int k, int l)
{
	//printf("UPDATE1 %d %d\n", k, l);
	int k2 = k;
	k += N;
	while (k > 0)
	{
		a[k2][l] ^= d1[l][k];
	    //if (d1[l][k])
	    //	printf("%d %d\n", k, l);
		k /= 2;	
	}	
}

void update2 (int k, int l)
{
	//printf("UPDATE2 %d %d\n", k, l);
	int l2 = l;
	l += N;
	while (l > 0)
	{
		a[k][l2] ^= d2[k][l];
	    //if (d2[k][l])
	    //	printf("%d %d\n", k, l);
		l /= 2;	
	}	
}

void invert1 (int v, int ll, int rr, int k)
{
	//printf("INVERT1 %d %d\n", l, r);
	if (l > rr || r < ll)
		return;
	if (l <= ll && r >= rr)
	{
		d1[k][v] ^= 1;
		//printf("%d %d\n", k, v);
		return;
	}
	int mm = (ll + rr) / 2;
	invert1(2 * v, ll, mm, k);
	invert1(2 * v + 1, mm + 1, rr, k); 
}

void invert2 (int v, int ll, int rr, int k)
{
	//printf("INVERT2 %d %d\n", l, r);
	if (l > rr || r < ll)
		return;
	if (l <= ll && r >= rr)
	{                      
	    d2[k][v]  ^= 1;
		//printf("%d %d\n", k, v);
		return;
	}
	int mm = (ll + rr) / 2;
	invert2(2 * v, ll, mm, k);
	invert2(2 * v + 1, mm + 1, rr, k); 
}


int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		gets(s);
		for (int j = 0; j < n; j++)
			a[i][j] = s[j] - '0';
	}
	N = 2048;
	for (int i = 0; i < n; i++)
	{
		int tmp = 0;
		//printf("%d\n", i);
		for (int j = i + 1; j < n; j++)
		{
			update1(i, j);
		   	update2(i, j);
		   	update1(j, i);
		   	update2(j, i);          
        }
        /*for (int g = 0; g < n; g++)
        {
        	for (int j = 0; j < n; j++)
        		printf("%d ", a[g][j]);
        	puts("");
        }*/
		for (int j = n - 1; j > i; j--)
			if (a[i][j] + a[i][j + 1] == 1)
			{
			    //cout << "j = " << j << endl;
			    ans++;
                l = i;
				r = j;
				invert1(1, 0, N - 1, j);
				//invert2(1, 0, N - 1, i);
				tmp++;
			}
		//cout << endl;
		for (int j = n - 1; j > i; j--)
			if (a[j][i] + a[j + 1][i] == 1)
			{
			    //cout << "j = " << j << endl;
				ans++;
				l = i;
				r = j;
				//invert1(1, 0, N - 1, i);
				invert2(1, 0, N - 1, j);
				tmp++;
			}
		update1(i, i);
		update2(i, i);
		if ((a[i][i] + tmp) % 2 == 1)
			ans++;
		//cout << ans << endl;
	}
	printf("%d\n", ans);
	return 0;
}