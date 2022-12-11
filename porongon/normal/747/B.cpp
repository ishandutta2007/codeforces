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
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define FOR(i,a,b) for(int i=a;i<(b);i++)
#define FORN(i,b) for(int i=0;i<(b);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<pair<int,int> > vii;

void porongueado(){puts("===");exit(0);}

int id[128];
char rid[4];
int q[4];
char s[256];
vi u;
int n;

int main(){
	id['A']=0;id['C']=1;id['G']=2;id['T']=3;
	rid[0]='A';rid[1]='C';rid[2]='G';rid[3]='T';
	scanf("%d%s",&n,s);
	if(n%4)porongueado();
	FORN(i,n){
		if(s[i]=='?')u.pb(i);
		else q[id[s[i]]]++;
	}
	int k=n/4;
	if(max(q[0],max(q[1],max(q[2],q[3])))>k)porongueado();
	FORN(i,u.size()){
		FORN(j,4){
			if(q[j]<k){
				s[u[i]]=rid[j];
				q[j]++;
				break;
			}
		}
	}
	puts(s);
	return 0;
}