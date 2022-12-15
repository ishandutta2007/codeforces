#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

using T = double;
const T inf = 1e100, eps = 1e-10, pi = acos(-1);

struct Pt
{
	T x, y;
	Pt() {}
	Pt (T x, T y) : x(x), y(y) {}

	Pt operator + (Pt p) const {return Pt(x + p.x, y + p.y); }
	Pt operator - (Pt p) const {return Pt(x - p.x, y - p.y); }
	Pt operator * (T k) const {return Pt(k * x, k * y); }
	Pt operator / (T k) const {return Pt( x/k, y/k); }

	bool operator == (Pt p) const
	{
		return fabs(x - p.x) < eps and fabs(y - p.y) < eps;
	}

};

struct Angle
{
	T theta;

	bool operator == (Angle o) const
	{
		return fabs(o.theta - theta) < eps;
	}

	bool operator < (Angle o) const
	{
		return theta + eps < o.theta;
	}
};

T dot(Pt a, Pt b)
{
	return a.x * b.x + a.y * b.y;
}

T cross(Pt a, Pt b)
{
	return a.x * b.y - a.y * b.x;
}

T getAngle(Pt a, Pt b)
{
	return atan2(cross(a, b), dot(a, b));
}

ll solve(void)
{
	int nbPoints;
	cin >> nbPoints;
	vector<Angle> angles(nbPoints);
	for (int i(0); i < nbPoints; ++i)
	{
		Pt a, b;
		cin >> a.x >> a.y >> b.x >> b.y;
		Pt v = b-a;
		angles[i] = {getAngle({0, 1}, v)};
		if (angles[i].theta < 0)
			angles[i].theta += 2 * pi;
	}
	map<Angle, int> cnt;
	ll ans(0);
	for (auto v : angles)
	{
		Angle t = {pi + v.theta};
		if (t.theta >= 2 * pi)
			t.theta -= 2 * pi;
		ans += cnt[t];
		cnt[v]++;
	}
	return ans;
}


int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		cout << solve() << '\n';
}