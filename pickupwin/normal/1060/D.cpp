#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN=100111;

int N;
int L[MAXN], R[MAXN];
long long Ans=0LL;

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	for(int i=1;i<=N;++i)	cin >> L[i] >> R[i];
	
	sort(L+1, L+N+1);
	sort(R+1, R+N+1);
	
	for(int i=1;i<=N;++i)
		Ans+=(long long)(max(L[i], R[i]));
	Ans+=(long long)(N);
	
	cout << Ans << endl;
	
	return 0;
}