#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
//
int n, k, h;
multiset <int> s;
vector <int> a;
int e[100000];
int start, stop;
int max = 0;
int s1 = 0;
//
int main() {
	//freopen("input.txt", "r", stdin);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> h;
		a.push_back(h);
	}
	//
	for (int i = 0; i < n; i++) {
		if (i==0) e[0] = 0; else e[i]= e[i-1];
		while ((e[i] < n)&&((s.empty())||((*s.rbegin())-(*s.begin())<=k))) {
			s.insert(a[e[i]]);
			e[i]++;
		}
		if (!((s.empty())||((*s.rbegin())-(*s.begin())<=k))) {
			e[i]--;
			s.erase(s.find(a[e[i]]));		
		}
		s.erase(s.find(a[i]));
	}
	//
	int max = -1; int sum = 0;
	for (int i = 0; i < n; i++)
		if (e[i]-i > max) {
			max = e[i]-i;
			sum=1;
		} else
		if (e[i]-i == max) sum++;
	//
	printf("%d %d\n", max, sum);
	for (int i = 0; i < n; i++) {
		if (e[i]-i == max) printf("%d %d\n", i+1, e[i]);
	}
	//
	return 0;
}