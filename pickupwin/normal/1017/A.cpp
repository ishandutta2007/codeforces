#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN=1011;

int N;
int A[MAXN], B[MAXN], C[MAXN], D[MAXN];
int Sum[MAXN], Rank[MAXN];

bool cmps(int a, int b){
	if(Sum[a]==Sum[b])	return a<b;
	return Sum[a]>Sum[b];
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	for(int i=1;i<=N;++i){
		cin >> A[i] >> B[i] >> C[i] >> D[i];
		Sum[i]=A[i]+B[i]+C[i]+D[i];
		Rank[i]=i;
	}
	
	sort(Rank+1, Rank+N+1, cmps);
	
	for(int i=1;i<=N;++i)
		if(Rank[i]==1){
			cout << i << endl;
			break;
		}
	
	return 0;
}