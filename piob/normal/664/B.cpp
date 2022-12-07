#include <bits/stdc++.h>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define ALL(a) (a).begin(), (a).end()
#define SIZE(a) ((int)(a).size())
#define VAR(x) #x ": " << x << " "
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define gcd __gcd
#define x first
#define y second
#define st first
#define nd second
#define pb push_back

using namespace std;

template<typename T> ostream& operator<<(ostream &out, const vector<T> &v){ out << "{"; for(const T &a : v) out << a << ", "; out << "}"; return out; }
template<typename S, typename T> ostream& operator<<(ostream &out, const pair<S,T> &p){ out << "(" << p.st << ", " << p.nd << ")"; return out; }

typedef long long LL;
typedef pair<int, int> PII;
typedef long double K;
typedef vector<int> VI;

const int dx[] = {0,0,-1,1}; //1,1,-1,1};
const int dy[] = {-1,1,0,0}; //1,-1,1,-1};

int n, m, pos, neg;
char buff[10];
vector<char> e;

bool possible(){
	return pos - neg*m <= n && n <= pos*m - neg;
}

int a, b;

void find_pos(){
	--pos;
	n -= a;
	while(!possible()) --n, ++a;
	printf("%d ", a);
}

void find_neg(){
	--neg;
	n += b;
	while(!possible()) ++n, ++b;
	printf("%d ", b);
}

int main(){
	pos = 1;
	for(;;){
		scanf("%s", buff);
		scanf("%s", buff);
		if(buff[0] == '=')
			break;
		e.push_back(buff[0]);
		if(buff[0] == '+')
			++pos;
		else
			++neg;
	}
	scanf("%d", &n);
	m = n;
	a = b = 1;
	if(!possible())
		printf("Impossible\n");
	else{
		printf("Possible\n");
		find_pos();
		for(char c : e){
			printf("%c ", c);
			if(c == '+')
				find_pos();
			else
				find_neg();
		}
		printf(" = %d\n", m);
	}
	return 0;
}