#include <bits/stdc++.h>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second
#define pb push_back
#define re real()
#define im imag()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef double K;
typedef vector<int> VI;

int dx[] = {0,0,-1,1}; //1,1,-1,1};
int dy[] = {-1,1,0,0}; //1,-1,1,-1};

int n;
string s, t;
vector<char> prv[256];
bool cycle;
vector<char> post;
int color[256];

void dfs(char u){
	color[u] = 1;
	for(char v : prv[u]){
		if(color[v] == 0){
			dfs(v);
		}else if(color[v] == 1){
			cycle = 1;
		}
	}
	color[u] = 2;
	post.push_back(u);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin >> n;
	FWD(r,0,n){
		cin >> t;
		bool diff = 0;
		FWD(i,0,min(s.size(), t.size())){
			if(s[i] != t[i]){
				prv[t[i]].push_back(s[i]);
				diff = 1;
				break;
			}
		}
		if(!diff && t.size() < s.size()){
			printf("Impossible\n");
			return 0;
		}
		s = t;
	}
	FWD(i,'a','z'+1)
		if(color[i] == 0)
			dfs(i);
	if(cycle)
		printf("Impossible\n");
	else{
		for(char c : post) printf("%c", c);
		printf("\n");
	}
	return 0;
}