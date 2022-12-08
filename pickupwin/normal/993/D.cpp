#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN=55;
const long long LONF=4567891012345678910LL;

int N;

struct Task{
	long long p, k, v;
} T[MAXN];

bool cmpv(Task A, Task B){
	return A.v>B.v;
}

bool cmpp(Task A, Task B){
	return A.p>B.p;
}

long long DP[MAXN][MAXN][MAXN];
int Dfn[MAXN][MAXN][MAXN], DFN;

long long Left, Right, Mid;

void relax(int i, int j, int k, long long v){
	if(Dfn[i][j][k]!=DFN)	DP[i][j][k]=v;
	else	DP[i][j][k]=min(DP[i][j][k], v);
	Dfn[i][j][k]=DFN;
}

bool In(int i, int j, int k){
	return Dfn[i][j][k]==DFN;
}

bool test(long long k){
	for(int i=1;i<=N;++i)	T[i].v=T[i].p*1000-T[i].k*k;
	//sort(T+1, T+N+1, cmpv);
	sort(T+1, T+N+1, cmpp);
	++DFN;
	relax(0, 0, 0, 0LL);
	for(int i=0;i<N;++i)
		for(int j=0;j<=N;++j)
			for(int k=0;k<=N;++k){
				if(!In(i, j, k))	continue;
				if(T[i+1].p==T[i+2].p){
					relax(i+1, j, k+1, DP[i][j][k]+T[i+1].v);
					//relax(i+1, j, k+1, DP[i][j][k]+T[i].v);
					//if(j>1)	relax(i+1, j-1, k, DP[i][j][k]);
					if(j>=1)	relax(i+1, j-1, k, DP[i][j][k]);
				}
				else{
					relax(i+1, j+k+1, 0, DP[i][j][k]+T[i+1].v);
					//relax(i+1, j+k+1, 0, DP[i][j][k]+T[i].v);
					//if(j>1)	relax(i+1, j+k-1, 0, DP[i][j][k]);
					if(j>=1)	relax(i+1, j+k-1, 0, DP[i][j][k]);
				}
			}
	/*
	if(k==1250){
		for(int i=1;i<=N;++i)
			for(int j=0;j<=N;++j)
				for(int k=0;k<=N;++k)
					if(In(i, j, k))
						cout << i << " " << j << " " << k << " " << DP[i][j][k] << endl;
	}
	*/
	long long ret=LONF;
	for(int j=0;j<=N;++j)
		for(int k=0;k<=N;++k)
			if(In(N, j, k)){
				//cout << "!" << endl;
				ret=min(ret, DP[N][j][k]);
			}
	return ret<=0LL;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	for(int i=1;i<=N;++i)
		cin >> T[i].p;
	for(int i=1;i<=N;++i)
		cin >> T[i].k;
	
	for(int i=1;i<=N;++i)	Right=max(Right, T[i].p*1000);
	while(Left<Right){
		Mid=(Left+Right)>>1;
		//cout << Mid << endl;
		if(test(Mid))	Right=Mid;
		else	Left=Mid+1;
	}
	Mid=(Left+Right)>>1;
	
	cout << Mid << endl;
	
	return 0;
}

/*
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN=55;
const long long LONF=4567891012345678910LL;

int N;
long long A[MAXN], B[MAXN];
long long Val[MAXN], Temp[MAXN];
long long DP[MAXN][MAXN][MAXN];

long long Left, Right, Mid;

bool test(long long k){
	for(int i=1;i<=N;++i)	Temp[i]=A[i]*1000-k*B[i];
	sort(Temp+1, Temp+N+1);
	for(int i=1, j=N;i<=N;++i, --j)	Val[i]=Temp[j];
	for(int i=0;i<=N;++i)
		for(int j=0;j<=N;++j)
			for(int k=0;k<=N;++k)
				DP[i][j][k]=LONF;
	DP[0][0][0]=0;
	for(int i=0;i<N;++i){
		for(int j=0;j<=N;++j){
			for(int k=0;k<=N;++k){
				if(DP[i][j][k]>=LONF)	continue;
				if(Val[i]==Val[i+1]){
					DP[i+1][j][k+1]=min(DP[i+1][j][k+1], DP[i][j][k]+Val[i]);
					if(j>1)	DP[i+1][j-1][k]=min(DP[i+1][j-1][k], DP[i][j][k]);
				}
				else{
					DP[i+1][j+k+1][0]=min(DP[i+1][j+k+1][0], DP[i][j][k]+Val[i]);
					if(j>1)	DP[i+1][j+k-1][0]=min(DP[i+1][j+k-1][0], DP[i][j][k]);
				}
			}
		}
	}
	long long ret=LONF;
	for(int i=0;i<=N;++i)
		for(int j=0;j<=N;++j)
			ret=min(ret, DP[N][i][j]);
	return ret<=0;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	for(int i=1;i<=N;++i)	cin >> A[i];
	for(int j=1;j<=N;++j)	cin >> B[j];
	
	for(int i=1;i<=N;++i)	Right=max(Right, A[i]*1000);
	while(Left<Right){
		Mid=(Left+Right)>>1;
		if(test(Mid))	Right=Mid;
		else	Left=Mid+1;
	}
	Mid=(Left+Right)>>1;
	
	cout << Mid << endl;
	
	return 0;
}
*/