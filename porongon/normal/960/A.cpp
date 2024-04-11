#include <algorithm>
#include <bitset>
#include <cassert>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#endif
#define mp make_pair
#define fst first
#define snd second
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<(b);i++)
#define FORN(i,b) for(int i=0;i<(b);i++)
#define SZ(x) ((int)(x).size())
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<pair<int,int> > vii;

char s[1<<20];

int main(){
	scanf("%s",s);
	int a=0,b=0,c=0;
	int i=0;
	while(s[i]=='a')i++,a++;
	while(s[i]=='b')i++,b++;
	while(s[i]=='c')i++,c++;
	if(s[i]||c!=a&&c!=b||!a||!b)puts("NO");
	else puts("YES");
	return 0;
}