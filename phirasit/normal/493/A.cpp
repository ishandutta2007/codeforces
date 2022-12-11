#include <iostream>
#include <set>

using namespace std;

class TEAM {
	public :
		set<int> yellow, red;
		string name;
}home, away;

int n;

int main() {
	cin >> home.name >> away.name >> n;
	for(int i = 0;i < n;i++) {
		int min, num;
		string team, card;
		cin >> min >> team >> num >> card;
		TEAM &t = (team == "h" ? home : away);
		if(t.red.count(num)) {
			continue;
		}
		if(card == "r") {
			t.red.insert(num);
			cout << t.name << " " << num << " " << min << endl;
		}else {
			if(t.yellow.count(num)) {
				t.red.insert(num);
				cout << t.name << " " << num << " " << min << endl;
			}else {
				t.yellow.insert(num);
			}
		}
	}
	return 0;
}