#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) ((a < 0) ? (-(a)) : (a))

const int N = (int)5e5 + 9;
char seq[N];
int link_l[N];
int link_r[N];
int brack[N];

int main(){
	fastIO;
	int n,m,p;
	cin>> n >> m >> p;
	stack<int>s;
	for(int i = 1;i<=n;i++){
		cin >> seq[i];
		if(seq[i] == '('){
			s.push(i);
		}
		else{
			brack[i] = s.top();
			brack[s.top()] = i;
			s.pop();
		}
	}
	for(int i = 1;i<=n;i++)
		link_l[i] = i-1,link_r[i] = i+1;
	link_r[0] = 1;
	link_l[n+1] = n;
	char cur;
	int lb,rb;
	int ai,bi;
	for(int j = 0;j<m;j++){
		cin >> cur;
		if(cur == 'L'){
			p = link_l[p];
		}
		else if(cur == 'R'){
			p = link_r[p];
		}
		else{
			lb = p;
			rb = brack[p];
			if(lb > rb)
				swap(lb,rb);
			ai = link_l[lb];
			bi = link_r[rb];
			link_r[ai] = bi;
			link_l[bi] = ai;
			if(link_r[rb] > n)
				p = link_l[lb];
			else
				p = link_r[rb];
		}
	}
	int y = link_r[0];
	while(y <= n){
		cout << seq[y];
		y = link_r[y];
	}
	return 0;
}