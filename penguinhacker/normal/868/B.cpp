#include <bits/stdc++.h>
using namespace std;

#define ll long long

int hands[3], region1, region2; //s, m, h
int h, m, s, t1, t2;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> h >> m >> s >> t1 >> t2;
	
	if (h==12)
		h=0;
	if (t1==12)
		t1=0;
	if (t2==12)
		t2=0;
	t1 *= 3600;
	t2 *= 3600;

	hands[2] = 3600*h + 60*m + s;
	hands[1] = 12*(60*m + s);
	hands[0] = 720*s;
	sort(hands, hands+3);

	if (hands[0] < t1 && t1 < hands[1])
		region1=1;
	else if (hands[1] < t1 && t1 < hands[2])
		region1=2;
	else
		region1=3;

	if (hands[0] < t2 && t2 < hands[1])
		region2=1;
	else if (hands[1] < t2 && t2 < hands[2])
		region2=2;
	else
		region2=3;
	
	if (region1 == region2)
		cout << "YES\n";
	else
    	cout << "NO\n";
	return 0;
}