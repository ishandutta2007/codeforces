							/* in the name of Allah */
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

bool mark[1010];
int cnt[40000];

int main(){
	int a, b;
	int p[4];
	while(cin >> p[0] >> p[1] >> p[2] >> p[3] >> a >> b){
		sort(p, p + 4);
		do{
			for(int i = a; i <= b; i++){
				int t = i;
				for(int j = 0; j < 4; j++)
					t %= p[j];
				if(i == t)
					cnt[i]++;
			}
		}
		while(next_permutation(p, p + 4));
		int res = 0;
		for(int i = a; i <= b; i++)
			if(cnt[i] >= 7)
				res++;
		cout << res << endl;
	}
	return 0;
}