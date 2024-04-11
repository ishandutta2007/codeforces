#include <bits/stdc++.h>

using namespace std;

struct Event {
	Event() = default;
	Event(long long time, int add, int index) : time(time), add(add), index(index) {}
	long long time = 0;
	int add = 0;
	int index = 0;
};
struct EventComparator {
	bool operator()(const Event& e1, const Event& e2) {
		return !(e1.time < e2.time || e1.time == e2.time && e1.add < e2.add || e1.time == e2.time && e1.add == e2.add && e1.index < e2.index);
	}
};

int main() {
	std::ios::sync_with_stdio(false);
	priority_queue<Event, vector<Event>, EventComparator> events_queue;
	int n, period;
	cin >> n >> period;
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		events_queue.push(Event(t, 1, i));
	}
	long long next_available_time = 0;
	set<int> in_queue;
	set<int> in_hungry;
	vector<long long> results(n);
	while (!events_queue.empty()) {
		long long current_time = events_queue.top().time;
		while (!events_queue.empty() && events_queue.top().time == current_time) {
			Event event = events_queue.top();
			events_queue.pop();
			if (event.add) {
				in_hungry.insert(event.index);
			} else {
				in_queue.erase(event.index);
			}
		}
		if (!in_hungry.empty()) {
			int h_index = *in_hungry.begin();
			if (in_queue.empty() || *in_queue.begin() > h_index) {
				next_available_time = max(next_available_time, current_time) + period;
				results[h_index] = next_available_time;
				in_hungry.erase(h_index);
				in_queue.insert(h_index);
				events_queue.push(Event(next_available_time, 0, h_index));
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		printf("%lld ", results[i]);
	}
	printf("\n");
	return 0;
}