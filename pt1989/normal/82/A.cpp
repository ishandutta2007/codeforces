//      hello world


//DS includes
#include<bitset>
#include<complex>
#include<deque>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>

//Other Includes
#include<algorithm>
#include<cassert>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<iostream>
#include<sstream>

#define oo 			0xBADC0DE
#define s(n)			scanf("%d",&n)
#define sl(n) 			scanf("%lld",&n)
#define sf(n) 			scanf("%lf",&n)
#define fill(a,v) 		memset(a, v, sizeof a)
#define ull 			unsigned long long
#define ll 				long long
#define bitcount 		__builtin_popcount
#define all(x) 			x.begin(), x.end()
#define pb( z ) 		push_back( z )
#define gcd				__gcd

#define FOR(i,n) for (int i=0; i < (n); i++)

using namespace std;
string names[] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
int main(int argc, char** argv) {
	int n;
	cin>>n;
	queue< pair<string, int> > q;
	for (int i=0; i < 5; i++)
		q.push( make_pair( names[i], 1 ) );
	while (q.size() > 0) {
		pair<string, int> z = q.front(); q.pop();
		string naam = z.first;
		int count = z.second;
		if (count >= n) {
			cout << naam << endl;
			break;
		}
		n -= count;
		q.push( make_pair(naam, count*2) );
	}
	return 0;
}