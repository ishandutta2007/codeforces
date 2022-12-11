#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int answer[8];
int cnt;

int ask(int x1, int y1, int x2, int y2){
	printf("? %d %d %d %d\n", x1, y1, x2, y2);
	fflush(stdout);
	int ans;
	scanf("%d", &ans);
	return ans;
}

void solve(int x1, int y1, int x2, int y2){ // its guranteed that x1 <= x2 and y1 <= y2
	int p;
	for(int i = 20; i >= 0; i -- ){
		p = (1 << i);
		if(x1 + p <= x2 and ask(x1 + p, y1, x2, y2))
			x1 += p;
	}
	for(int i = 20; i >= 0;i -- ){
		p = (1 << i);
		if(y1 + p <= y2 and ask(x1, y1 + p, x2, y2))
			y1 += p;
	}
	for(int i = 20; i >= 0; i -- ){
		p = (1 << i);
		if(x2 - p >= x1 and ask(x1, y1, x2 - p, y2))
			x2 -= p;
	}
	for(int i = 20; i >= 0; i -- ){
		p = (1 << i);
		if(y2 - p >= y1 and ask(x1, y1, x2, y2 - p))
			y2 -= p;
	}
	answer[cnt ++ ] = x1;
	answer[cnt ++ ] = y1;
	answer[cnt ++ ] = x2;
	answer[cnt ++ ] = y2;
}

int main(){
	int n;
	scanf("%d", &n);
	int l = 1, r = n;
	int md;
	int a, b;
	bool ok = false;
	int cut;
	while(l < r){
		md = (l + r) / 2;
		a = ask(1, 1, md, n);
		b = ask(md + 1, 1, n, n);
		if(a == 1 and b == 1){
			ok = true;
			cut = md;
			break;
		}
		else{
			if(a <= b)
				l = md + 1;
			else
				r = md;
		}
	}
	if(ok){
		solve(1, 1, cut, n);
		solve(cut + 1, 1, n, n);
	}
	else{ 
		l = 1, r = n;
		ok = false;
		while(l < r){
			md = (l + r) / 2;
			a = ask(1, 1, n, md);
			b = ask(1, md + 1, n, n);
			if(a == 1 and b == 1){
				ok = true;
				cut = md;
				break;
			}
			else{
				if(a <= b)
					l = md + 1;
				else
					r = md;
			}
		}
		solve(1, 1, n, cut);
		solve(1, cut + 1, n, n);
	}
	printf("! %d %d %d %d %d %d %d %d\n", answer[0], answer[1], answer[2], answer[3], answer[4], answer[5], answer[6], answer[7]);
	return 0;
}