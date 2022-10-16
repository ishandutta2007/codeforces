#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;
typedef vector < int > vi;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 18;
const int OFF = (1 << OFF);

vector < pii > sol;
int n, A[N], gdje[N];
vector < pii > saz;

int main(){
	scanf("%d", &n);
	for(int i = 0;i < n;i++){
		scanf("%d", A + i);
		saz.PB({A[i], i});
	}
	sort(saz.begin(), saz.end());
	for(int i = 0;i < n;i++){
		A[i] = lower_bound(saz.begin(), saz.end(), (pii){A[i], i}) - saz.begin();
		gdje[A[i]] = i;
	}
	for(;;){
		bool nasao = 0;
		for(int raz = 1;raz < n;raz++){
			for(int i = 0;i + raz < n;i++){
				if(gdje[i] > gdje[i + raz]){
					sol.PB({gdje[i + raz], gdje[i]});
					swap(gdje[i], gdje[i + raz]);
					nasao = 1;
				}
				if(nasao)
					break;
			}
			if(nasao)
				break;
		}
		if(!nasao)
			break;
	}
	for(int i = 0;i < n;i++){
		if(gdje[i] != i){
			printf("-1\n");
			return 0;
		}
	}
	printf("%d\n", (int)sol.size());
	for(pii tmp : sol){	
		printf("%d %d\n", tmp.X + 1, tmp.Y + 1);
	}
	return 0;
}