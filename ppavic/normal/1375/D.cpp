#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;
typedef vector < int > vi;

const int N = 3e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 18;
const int OFF = (1 << OFF);

int T, n, A[N], bio[N], sol[N], siz = 0;

inline int get_mex(){
	for(int i = 0;i <= n;i++)
		bio[i] = 0;
	for(int i = 0;i < n;i++)
		bio[A[i]]++;
	int ret = 0;
	for(;bio[ret];ret++);
	return ret;
}

int main(){
	scanf("%d", &T);
	for(;T--;){
		scanf("%d", &n);
		for(int i = 0;i < n;i++)
			scanf("%d", A + i);
		for(;;){
			int sad = get_mex();
			if(sad == n){
				int koga = n;
				for(int i = 0;i < n;i++)
					if(A[i] != i)	
						koga = i;
				if(koga == n)
					break;
				A[koga] = sad;
				sol[siz++] = koga + 1;
			}
			sad = get_mex();
			if(A[sad] != sad){
				A[sad] = sad;
				sol[siz++] = sad + 1;
			}
			
		}
		//printf("\n res : \n");
		//for(int i = 0;i < n;i++)
		//	printf("%d ", A[i]);
		//printf("\n");
		printf("%d\n", siz);
		for(int i = 0;i < siz;i++)
			printf("%d ", sol[i]);
		siz = 0; printf("\n"); 
	}
	return 0;
}