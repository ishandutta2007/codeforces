#include <bits/stdc++.h>

typedef long long ll;

std::vector<ll> Px, Py;

inline ll myabs(ll x) { return x >= 0 ? x: -x; }

inline ll mah(ll XA, ll YA, ll XB, ll YB)
{
	return myabs(XA - XB) + myabs(YA - YB);
}

int main()
{
	ll x0, y0, ax, ay, bx, by, xs, ys, t;
	std::cin >> x0 >> y0 >> ax >> ay >> bx >> by >> xs >> ys >> t;
	ll x = x0, y = y0;
	Px.push_back(0); Py.push_back(0);
	while (x <= 2e16 && y <= 2e16)
	{
		Px.push_back(x); Py.push_back(y);
		x = ax * x + bx, y = ay * y + by;
	}
	long long ans = 0;
	int size = Px.size();
	for (int i = 1; i <= size; ++i)
	{
		for (int j = 1; j <= i; ++j) //  S  i i  j j   i + 1, i + 2, ...
		{
			//printf("Working on %d %d\n", i, j);
			ll nowans = 0;
			ll __t = mah(xs, ys, Px[i], Py[i]);
			if (__t <= t)
			{
				//printf("OK. From %d %d to %d %d\n", xs, ys, Px[i], Py[i]);
				++nowans;
			}
			else
			{
				//printf("END\n");
				ans = std::max(ans, nowans);
				continue;
			}
			for (int k = i - 1; k >= j; --k) 
			{
				__t += mah(Px[k], Py[k], Px[k + 1], Py[k + 1]);
				if (__t <= t) 
				{
					++nowans;
					
					//printf("OK. From %d %d to %d %d\n", Px[k + 1], Py[k + 1], Px[k], Py[k]);
				}
				else
				{
					//puts("END");
					ans = std::max(ans, nowans);
					continue;
				}
			}
			if (i == size) continue;
			__t += mah(Px[j], Py[j], Px[i + 1], Py[i + 1]);
			if (__t <= t) 
			{
				//printf("OK. From %d %d to %d %d\n", Px[j], Py[j], Px[i+1], Py[i+1]);
				++nowans;
			}
			else
			{
				//puts("END");
				ans = std::max(ans, nowans);
				continue;
			}
			for (int k = i + 1; k < size; ++k)
			{
				__t += mah(Px[k], Py[k], Px[k + 1], Py[k + 1]);
				if (__t <= t) ++nowans;
				else
				{
					ans = std::max(ans, nowans);
					continue;
				}
			}
			ans = std::max(ans, nowans);
		}
		for (int j = i + 1; j <= size; ++j) //  S  i i  j j   i - 1, i - 2, ...
		{
			//printf("Working on %d %d\n", i, j);
			ll nowans = 0;
			ll __t = mah(xs, ys, Px[i], Py[i]);
			if (__t <= t)
			{
				//printf("OK. From %d %d to %d %d\n", xs, ys, Px[i], Py[i]);
				++nowans;
			}
			else
			{
				//printf("END\n");
				ans = std::max(ans, nowans);
				continue;
			}
			for (int k = i; k < size; ++k) 
			{
				__t += mah(Px[k], Py[k], Px[k + 1], Py[k + 1]);
				if (__t <= t) 
				{
					++nowans;
					
					//printf("OK. From %d %d to %d %d\n", Px[k + 1], Py[k + 1], Px[k], Py[k]);
				}
				else
				{
					//puts("END");
					ans = std::max(ans, nowans);
					continue;
				}
			}
			if (i == 1) continue;
			__t += mah(Px[j], Py[j], Px[i - 1], Py[i - 1]);
			if (__t <= t) 
			{
				//printf("OK. From %d %d to %d %d\n", Px[j], Py[j], Px[i+1], Py[i+1]);
				++nowans;
			}
			else
			{
				//puts("END");
				ans = std::max(ans, nowans);
				continue;
			}
			for (int k = i - 1; k > 0; --k)
			{
				__t += mah(Px[k], Py[k], Px[k - 1], Py[k - 1]);
				if (__t <= t) ++nowans;
				else
				{
					ans = std::max(ans, nowans);
					continue;
				}
			}
			ans = std::max(ans, nowans);
		}
	}
	printf("%lld", ans);
}