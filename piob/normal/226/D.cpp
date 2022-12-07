#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define SIZE(a) ((int)a.size())

using namespace std;

int n, m;
int M[110][110];
int R[110], C[110];
bool RS[110], CS[110];

int main(){
	int z;
	//scanf("%d", &z);
	z = 1;
	while(z--){
		scanf("%d %d", &n, &m);
		FWD(i,0,n)
			FWD(j,0,m)
				scanf("%d", &M[i][j]);
		FWD(i,0,n){
			R[i] = 0;
			C[i] = 0;
		}
		FWD(i,0,n)
			FWD(j,0,m){
				R[i] += M[i][j];
				C[j] += M[i][j];
			}
		for(;;){
			int r = -1;
			FWD(i,0,n) if(R[i] < 0) r = i;
			if(r != -1){
				R[r] = -R[r];
				RS[r] = !RS[r];
				FWD(j,0,m){
					C[j] = C[j] - 2*M[r][j];
					M[r][j] = -M[r][j];
				}
				continue;
			}
			int c = -1;
			FWD(j,0,m) if(C[j] < 0) c = j;
			if(c != -1){
				C[c] = -C[c];
				CS[c] = !CS[c];
				FWD(i,0,n){
					R[i] = R[i] - 2*M[i][c];
					M[i][c] = -M[i][c];
				}
				continue;
			}
			break;
		}
		vector<int> WR, WC;
		FWD(i,0,n) if(RS[i]) WR.push_back(i);
		printf("%d ", SIZE(WR));
		for(int x : WR) printf("%d ", x+1);
		printf("\n");

		FWD(j,0,m) if(CS[j]) WC.push_back(j);
		printf("%d ", SIZE(WC));
		for(int x : WC) printf("%d ", x+1);
		printf("\n");
	}
	return 0;
}