#include <bits/stdc++.h>
#define err(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
      
#define TASK "linkedmap"

using namespace std;

const int dd = (int)57;

string A[dd];
vector<int> R[dd], C[dd], uR, uC;

void addC(int j);

void addR(int i) {
	if ((int)R[i].size()) uR.push_back(i);
	auto K = R[i];
	R[i] = vector<int>(0);
	for (auto j : K)
		addC(j);
}

void addC(int j) {
	if ((int)C[j].size()) uC.push_back(j);
	auto K = C[j];
	C[j] = vector<int>(0);
	for (auto i : K)
		addR(i);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    	cin >> A[i];

    for (int i = 0; i < n; ++i)
    	for (int j = 0; j < m; ++j) if (A[i][j] == '#')
    		R[i].push_back(j), C[j].push_back(i);
    
    for (int i = 0; i < n; ++i) if ((int)R[i].size()) {
    	uR = uC = vector<int>(0);
    	addR(i);

    	for (int i : uR) for (int j : uC)
    		if (A[i][j] != '#') return 0 * puts("No");
    }
    puts("Yes");
    return 0;
}