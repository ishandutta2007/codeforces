#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;
typedef long double K;

const K PI = acos((long double)-1);

int P[100010];
vector<int> D;

void dissolve(int x){
	D.clear();
	while(x > 1){
		int d = P[x];
		D.push_back(d);
		while(x%d == 0)
			x /= d;
	}
}

int n, m;
int G[100010];
bool ON[100010];

int main(){
	for(int i = 2; i < 100010; ++i)
		if(P[i] == 0){
			P[i] = i;
			if(i < 1000)
				for(int j = i*i; j < 100010; j += i)
					P[j] = i;
		}
	scanf("%d %d", &n, &m);
	FWD(i,0,m){
		char cmd[3];
		int k;
		scanf("%s %d", cmd, &k);
		if(cmd[0] == '+'){
			if(ON[k])
				printf("Already on\n");
			else{
				dissolve(k);
				int c = 0;
				for(int d : D)
					if(G[d])
						c = G[d];
				if(c)
					printf("Conflict with %d\n", c);
				else{
					for(int d : D)
						G[d] = k;
					printf("Success\n");
					ON[k] = 1;
				}
			}
		}else{
			if(!ON[k])
				printf("Already off\n");
			else{
				dissolve(k);
				for(int d : D)
					if(G[d])
						G[d] = 0;
				printf("Success\n");
				ON[k] = 0;
			}
		}

	}
	return 0;
}