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

struct point {
	int C[3];	
};

point operator+(point a, point b){
	point c;
	FWD(i,0,3) c.C[i] = a.C[i] + b.C[i];
	return c;
}

point operator-(point a, point b){
	point c;
	FWD(i,0,3) c.C[i] = a.C[i] - b.C[i];
	return c;
}

bool samep(point a, point b){
	int A[3], B[3];
	FWD(i,0,3) A[i] = a.C[i], B[i] = b.C[i];	
	sort(A, A+3);
	sort(B, B+3);
	FWD(i,0,3) if(A[i] != B[i]) return 0;
	return 1;
}

bool zero(point a){
	FWD(i,0,3) if(a.C[i]) return 0;
	return 1;
}

LL dot(point a, point b){
	LL x = 0;
	FWD(i,0,3) x += (LL)a.C[i] * (LL)b.C[i];
	return x;
}

point P[8];
int perm[8];

int main(){
	FWD(i,0,8)
		FWD(j,0,3)
			scanf("%d", &P[i].C[j]);
	FWD(i,0,8)
		sort(P[i].C, P[i].C+3);
	FWD(i,0,8) perm[i] = i;
	do{
		int a = perm[0];
		int b = perm[1];
		int c = perm[2];
		int d = perm[3];
		do{
		do{
		do{
			point B = P[b] - P[a];
			point C = P[c] - P[a];
			point D = P[d] - P[a];
			if(zero(B) || zero(C) || zero(D))
				continue;
			if(dot(B, C) || dot(C, D) || dot(B, D))
				continue;
			if(dot(B, B) != dot(C, C) || dot(B, B) != dot(D, D))
				continue;
			
			if(samep(P[a] + B + C, P[perm[4]]))
			if(samep(P[a] + B + D, P[perm[5]]))
			if(samep(P[a] + C + D, P[perm[6]]))
			if(samep(P[a] + B + C + D, P[perm[7]])){
				P[perm[4]] = P[a] + B + C;
				P[perm[5]] = P[a] + B + D;
				P[perm[6]] = P[a] + C + D;
				P[perm[7]] = P[a] + B + C + D;
				printf("YES\n");
				FWD(i,0,8){
					FWD(j,0,3) printf("%d ", P[i].C[j]);
					printf("\n");
				}
				return 0;
			}
		}while(next_permutation(P[b].C, P[b].C+3));
		}while(next_permutation(P[c].C, P[c].C+3));
		}while(next_permutation(P[d].C, P[d].C+3));
	}while(next_permutation(perm+1, perm+8));
	printf("NO\n");
	return 0;
}