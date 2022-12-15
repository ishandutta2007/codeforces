#include <bits/stdc++.h>
using namespace std;

struct Segment
{
	int l, r;

	bool operator<(Segment other) const
	{
		return l < other.l;
	}

	pair<Segment, Segment> split(int pos) const
	{
		if (pos == l and pos == r)
			return make_pair((Segment){-1, -1}, (Segment){-1, -1});
		if (pos == l)
			return make_pair((Segment){l+1, r}, (Segment){-1, -1});
		if (pos == r)
			return make_pair((Segment){l, r-1}, (Segment){-1, -1});
		return make_pair((Segment){l, pos-1}, (Segment){pos+1, r});
	}
};

struct Event
{
	int pos, val;

	bool operator<(Event other) const
	{
		return val > other.val;
	}
};

const int MAXN = 1e5;

map<int, int> counter;
Event events[MAXN];
set<Segment> segments;
int ans(0), max_segments(1);
int N;

void read_input(void)
{
	cin >> N;

	for (int i(0); i < N; ++i)
	{
		int a;
		cin >> a;
		ans = max(ans, a + 1);
		events[i] = {i, a};
	}
	sort(events, events + N);
	segments.insert({0, N-1});
	counter[N]++;
}

void update(int index)
{
	auto it = segments.upper_bound({events[index].pos, events[index].pos});
	--it;
	auto split = it->split(events[index].pos);
	
	counter[it->r - it->l + 1]--;
	if (counter[it->r - it->l + 1] == 0)
		counter.erase(it->r - it->l + 1);
	segments.erase(it);

	if (split.first.l != -1)
	{
		segments.insert(split.first);
		counter[split.first.r - split.first.l + 1]++;
	}
	if (split.second.l != -1)
	{
		segments.insert(split.second);
		counter[split.second.r - split.second.l + 1]++;
	}
	if (counter.size() == 1 and segments.size() >= max_segments)
	{
		max_segments = segments.size();
		ans = events[index + 1].val + 1;
	}
}

int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	read_input();
	for (int i(0); i < N - 1; ++i)
		update(i);
	cout << ans << endl;
}