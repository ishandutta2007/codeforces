#include <bits/stdc++.h>
using namespace std;

set < pair <int, int> > s;
set < pair <pair <int , int>, int> > end[2];
int n, d;

int dx[] = {0, 1, 1,  1,  0, -1, -1, -1};
int dy[] = {1, 1, 0, -1, -1, -1,  0,  1};

int main() {
	cin >> n;
	cin >> d;
	
	for (int i = 0; i < d; i++)
		s.insert (make_pair (0, i));
	
	end[0].insert (make_pair (make_pair (0, d - 1), 0));
	
	for (int i = 1; i < n; i++) {
		cin >> d;
		
		end[i & 1].clear();
		for (set < pair <pair <int , int>, int> > :: iterator it = end[i & 1 ^ 1].begin(); it != end[i & 1 ^ 1].end(); ++it) {
			pair <int, int> posnow = it -> first;
			
			int nextdir = (it -> second + 1) % 8;
			int prevdir = (it -> second + 7) % 8;
			
			for (int j = 1; j <= d; j++) {
				s.insert (make_pair (posnow.first + dx[prevdir] * j, posnow.second + dy[prevdir] * j));
				s.insert (make_pair (posnow.first + dx[nextdir] * j, posnow.second + dy[nextdir] * j));
			}
			
			end[i & 1].insert (make_pair (make_pair (posnow.first + dx[nextdir] * d, posnow.second + dy[nextdir] * d), nextdir));
			end[i & 1].insert (make_pair (make_pair (posnow.first + dx[prevdir] * d, posnow.second + dy[prevdir] * d), prevdir));			
		}
	}
	
	cout << s.size() << endl;
	
	return 0;
}