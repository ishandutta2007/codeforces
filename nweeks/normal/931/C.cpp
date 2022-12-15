#include <bits/stdc++.h>

#define FOR(i, j, n) for (int i(j); i < n; ++i)
#define FORR(v, c) for (auto &v : c)
#define F first
#define S second
#define SQ(x) (x)*(x)
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define dbg(x) std::cerr<<#x<<" = " << (x) << std::endl
#define pnl(x) std::cout << x << '\n'
#define pns(x) std::cout << x << ' '
#define read(x) std::cin >> x
#define read2(x,y) std::cin >> x >> y
#define read3(x, y, z) std::cin >> x >> y >> z
#define read4(a, b, c, d) std::cin >> a >> b >> c >> d
#define readv(v) FORR(c,v) read(c)

struct Arrete { int v, c;};
struct Point {int x, y; double distance(Point other) const {return sqrt(SQ(x-other.x)+SQ(y-other.y));}};

typedef	std::vector<int>	vi;
typedef std::pair<int,int>	ii;
typedef std::vector<std::string>	vs;
typedef std::vector<ii>	vii;
typedef std::vector<Arrete>	vg;
typedef std::vector<long long>	vl;
typedef	long long ll;

const int	NB_D = 4;
const int	DY[] = {-1, 1, 0, 0};
const int	DX[] = {0, 0, -1, 1};

int		main(void)
{
	std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
	
	int	n; read(n);
	vi	arr(n);
	vi	numbers;

	std::set<int>	seen;

	for (auto&v : arr)
	{
		read(v);
		if (seen.find(v) != seen.end())
			continue ;
		else
			numbers.pb(v), seen.insert(v);
	}

		

	std::sort(all(numbers));

	if (numbers.size() == 1 or (numbers.size() == 2 and numbers[0] + 2 != numbers[1]))
	{
		pnl(n);
		for (auto v : arr)
			pns(v);
		std::cout << std::endl;
		return 0;
	}
	if (numbers.size() == 2)
	{
		numbers.pb(numbers[1]);
		numbers[1] = numbers[0]+1;
	}

	int	a(0), b(0), c(0);
	int	ba(0), bb(0), bc(0);
	FORR(v, arr)
		a+=v==numbers[0];
	FORR(v,arr)
		b += v == numbers[1];
	FORR(v, arr)
		c += v==numbers[2];
	
	ba = a, bb = b, bc = c;
	int	rem = std::min(a, c);
	b += 2 * rem;
	a -= rem;
	c -= rem;

	int		first_ans = std::min(a,ba) + std::min(b,bb) + std::min(c, bc);
	int		ans[3] = {a,b,c};
	
	a = ba, b = bb, c = bc;

	a += b/2, c += b/2, b%=2;
	int		second_ans = std::min(a,ba) + std::min(b, bb) + std::min(c, bc);;

	if (first_ans < second_ans)
	{
		pnl(first_ans);
		while (ans[0]--)
			pns(numbers[0]);		
		while(ans[1]--)
			pns(numbers[1]);
		while (ans[2]--)
			pns(numbers[2]);
	}
	else
	{
		pnl(second_ans);
		while (a--)
			pns(numbers[0]);
		while (b--)
			pns(numbers[1]);
		while (c--)
			pns(numbers[2]);
	}
	std::cout << std::endl;
}