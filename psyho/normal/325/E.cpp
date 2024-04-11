#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

int n;
int m;
int q[100001];
int was[100001];
int w[100001];
int p[100001];
int in[100001];
int bad = 0;

int go (int x, int y) {
	p[x] = rand() & 1;
    q[y] = x;
    if (x == n / 2) {
		if (y != n - 1) re 0;
        for (int i = 0; i <= y; i++) printf ("%d ", q[i]);
        printf ("0\n");
        re 1;
    }
    was[x] = 1;
    int a = (2 * x + p[x]) % n;
    int b = (2 * x + 1 - p[x]) % n;
	in[a]--;
	in[b]--;
	
	int runs = 0;
    if (!was[a] && (in[b] || was[b])) {
		runs++; 
		if (go (a, y + 1)) re 1;
	}
	if (!was[b] && (in[a] || was[a])) {
		runs++; 
		bad -= runs == 2; 
		if ((runs == 1 || bad > 0) && go(b, y + 1)) re 1;
	}
	
    was[x] = 0;
	in[a]++;
	in[b]++;
    re 0;
}

int main () {
	srand(3);
    scanf ("%d", &n);
	rep(i,n) in[i] = 2;
    if (n & 1) printf ("-1"); else {
        do {
            bad = 12;
            if (go (0, 0)) re 0;
        } while (true);
    }
    return 0;
}