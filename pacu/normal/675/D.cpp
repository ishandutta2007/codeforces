#include <iostream>
#include <set>
using namespace std;

set<int> S;
set<int> l,r;

int main()
{
	int N;
	int a;
	cin >> N;
	cin >> a;
	S.insert(a);
	l.insert(a);
	r.insert(a);
	S.insert(0);
	S.insert(1000000001);
	for(int i=1;i<N;i++)
	{
		cin >> a;
		set<int>::iterator it = S.lower_bound(a);
		int high = *it;
		it--;
		int low = *it;
		if(l.find(high)!=l.end()) cout << high << '\n';
		else cout << low << '\n';
		S.insert(a);
		l.insert(a);
		r.insert(a);
		l.erase(high);
		r.erase(low);
	}
}