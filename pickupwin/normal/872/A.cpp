#include <iostream>
using namespace std;
const int MAXN=11;
int N, M;
bool A[MAXN], B[MAXN];
int main(){
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for(int i=1, k;i<=N;++i){
		cin >> k;
		A[k]=true;
	}
	for(int i=1, k;i<=M;++i){
		cin >> k;
		B[k]=true;
	}
	for(int i=1;i<=9;++i)
		if(A[i] && B[i]){
			cout << i << endl;
			return 0;
		}
	for(int i=10, a, b;i<=99;++i){
		a=i/10;b=i%10;
		if((A[a] && B[b]) || A[b] && B[a]){
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}